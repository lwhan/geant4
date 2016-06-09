//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: G4BREPSolidCone.cc,v 1.15 2006/06/29 18:41:16 gunter Exp $
// GEANT4 tag $Name: geant4-09-01 $
//
// ----------------------------------------------------------------------
// GEANT 4 class source file
//
// G4BREPSolidCone.cc
//
// ----------------------------------------------------------------------

#include "G4BREPSolidCone.hh"
#include "G4FPlane.hh"
#include "G4FConicalSurface.hh"
#include "G4FCylindricalSurface.hh"
#include "G4CircularCurve.hh"

G4BREPSolidCone::G4BREPSolidCone(const G4String& name,
				 const G4ThreeVector& origin,
				 const G4ThreeVector& axis,
				 const G4ThreeVector& direction,
				 G4double length,
				 G4double radius,
				 G4double large_radius)
  : G4BREPSolid(name)
{
  SurfaceVec              = new G4Surface*[3];
  G4Point3D    ArcStart1  = G4Point3D(origin + (radius*direction));
  G4Vector3D   tmpaxis(axis);
  G4Vector3D   tmporigin(origin);  
  G4Point3D    tmppoint;

  tmppoint= G4Point3D(origin) + (length*tmpaxis);
  G4Point3D origin2(tmppoint.x(), tmppoint.y(), tmppoint.z());

  tmppoint=  origin2 + (large_radius*tmpaxis);
  G4Point3D ArcStart2(tmppoint.x(), tmppoint.y(), tmppoint.z());

  G4Ray::Vcross(tmpaxis, axis, direction);
  G4ThreeVector axis2(tmpaxis.x(),tmpaxis.y(), tmpaxis.z());

  G4CurveVector CVec;
  G4CircularCurve* tmp;

  tmp = new G4CircularCurve();
  tmp->Init(G4Axis2Placement3D(direction, axis2, origin) , large_radius);
  tmp->SetBounds(ArcStart1, ArcStart1);
  CVec.push_back(tmp);

  tmp = new G4CircularCurve();
  tmp->Init(G4Axis2Placement3D(direction, axis2, origin2), large_radius);
  tmp->SetBounds(ArcStart2, ArcStart2);
  CVec.push_back(tmp);

  SurfaceVec[0] = new G4FConicalSurface(tmporigin, axis, 
					length, radius, large_radius);
  SurfaceVec[0]->SetBoundaries(&CVec);

  // new G4AdvancedFace("G4FConicalSurface", tmporigin, direction, 
  // axis, CVec, 1, 0,0,length, radius, large_radius);

  // Create end planes & boundaries for cone solid
  G4CurveVector CVec2;
  tmp = new G4CircularCurve();
  tmp->Init(G4Axis2Placement3D(direction, axis2, origin), radius);
  tmp->SetBounds(ArcStart1, ArcStart1);
  CVec2.push_back(tmp);

  SurfaceVec[1] = new G4FPlane(tmpaxis, direction, origin2);
  //new G4AdvancedFace("G4FPlane" , origin2, direction, tmpaxis, CVec2, 1);
  SurfaceVec[1]->SetBoundaries(&CVec2);

  CVec2[0] = tmp = new G4CircularCurve();
  tmp->Init(G4Axis2Placement3D(direction, axis2, origin2), large_radius);
  tmp->SetBounds(ArcStart2, ArcStart2);

  SurfaceVec[2] = new G4FPlane(tmpaxis, direction, origin);
  //new G4AdvancedFace("G4FPlane", origin, direction, tmpaxis, CVec2, 1);  
  SurfaceVec[2]->SetBoundaries(&CVec2);

  nb_of_surfaces = 3;
  active=1;
  
  // Save constructor parameters
  constructorParams.origin       = origin;
  constructorParams.axis         = axis;
  constructorParams.direction    = direction;
  constructorParams.length       = length;
  constructorParams.radius       = radius;
  constructorParams.large_radius = large_radius;
  
  Initialize();
}

G4BREPSolidCone::G4BREPSolidCone( __void__& a )
  : G4BREPSolid(a)
{
}

G4BREPSolidCone::~G4BREPSolidCone()
{
}

void G4BREPSolidCone::Initialize()
{
  // Calc bounding box for solids and surfaces
  // Convert concave planes to convex     
  ShortestDistance=1000000;
  CheckSurfaceNormals();
  if(!Box || !AxisBox)
    IsConvex();
  CalcBBoxes();
}

EInside G4BREPSolidCone::Inside(register const G4ThreeVector& Pt) const
{
  G4double dist1 = SurfaceVec[0]->HowNear(Pt);
  G4double dist2 = SurfaceVec[1]->ClosestDistanceToPoint(Pt);
  G4double dist3 = SurfaceVec[2]->ClosestDistanceToPoint(Pt);  
  if(dist1 > dist2) dist1 = dist2;
  if(dist1 > dist3) dist1 = dist3;  
  if(dist1 > 0) return kInside;
  if(dist1 < 0) return kOutside;
  return kSurface;
}

G4ThreeVector G4BREPSolidCone::SurfaceNormal(const G4ThreeVector& Pt) const
{
  G4Vector3D n =  SurfaceVec[0]->Normal(Pt);
  G4ThreeVector norm(n.x(), n.y(), n.z());
  return norm;
}

G4double G4BREPSolidCone::DistanceToIn(const G4ThreeVector& Pt) const
{
  G4double dist1 = std::fabs(SurfaceVec[0]->HowNear(Pt));
  G4double dist2 = std::fabs(SurfaceVec[1]->ClosestDistanceToPoint(Pt));
  G4double dist3 = std::fabs(SurfaceVec[2]->ClosestDistanceToPoint(Pt));  
  if(dist1 > dist2) dist1 = dist2;
  if(dist1 > dist3) dist1 = dist3;  
  return dist1;
 
}

G4double G4BREPSolidCone::DistanceToIn(register const G4ThreeVector& Pt, 
				       register const G4ThreeVector& V) const
{
  Reset();  
  G4Vector3D Pttmp(Pt);
  G4Vector3D Vtmp(V);   
  //  G4double kInfinity = 10e20;
  G4Ray r(Pttmp, Vtmp);

  if(SurfaceVec[0]->Intersect( r ))
  {
    ShortestDistance = SurfaceVec[0]->GetDistance();
    return ShortestDistance;
  }
  return kInfinity; 
}

G4double G4BREPSolidCone::DistanceToOut(register const G4ThreeVector& Pt, 
					register const G4ThreeVector& V, 
					const G4bool, 
					G4bool *validNorm, 
					G4ThreeVector *) const
{
  if(validNorm)
    *validNorm = false;
  Reset();  

  G4Vector3D Pttmp(Pt);
  G4Vector3D Vtmp(V);   
  //  G4double kInfinity = 10e20;

  G4Ray r(Pttmp, Vtmp);
  if(SurfaceVec[0]->Intersect( r ))
  {
    ShortestDistance = SurfaceVec[0]->GetDistance();
    return ShortestDistance;
  }
  return kInfinity; 
}

G4double G4BREPSolidCone::DistanceToOut(const G4ThreeVector& Pt) const
{
  G4double dist1 = std::fabs(SurfaceVec[0]->HowNear(Pt));
  G4double dist2 = std::fabs(SurfaceVec[1]->ClosestDistanceToPoint(Pt));
  G4double dist3 = std::fabs(SurfaceVec[2]->ClosestDistanceToPoint(Pt));  
  if(dist1 > dist2) dist1 = dist2;
  if(dist1 > dist3) dist1 = dist3;  
  return dist1;
}

// Streams solid contents to output stream.
std::ostream& G4BREPSolidCone::StreamInfo(std::ostream& os) const
{
  G4BREPSolid::StreamInfo( os )
  << "\n origin:       " << constructorParams.origin
  << "\n axis:         " << constructorParams.axis
  << "\n direction:    " << constructorParams.direction
  << "\n length:       " << constructorParams.length
  << "\n radius:       " << constructorParams.radius
  << "\n large_radius: " << constructorParams.large_radius
  << "\n-----------------------------------------------------------\n";

  return os;
}

