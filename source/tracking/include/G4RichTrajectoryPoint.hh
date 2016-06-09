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
//
// $Id: G4RichTrajectoryPoint.hh,v 1.5 2006/09/27 20:42:52 asaim Exp $
// GEANT4 tag $Name: geant4-09-01 $
//
//---------------------------------------------------------------
//
// G4RichTrajectoryPoint.hh
//
// class description:
//   This class extends G4TrajectoryPoint.
//   From G4Trajectory, the following information is included:
//     1) Position (end of step).
//   The extended information, only publicly accessible through AttValues,
//   includes:
//     2) Auxiliary points, as in G4SmoothTrajectory.
//     3) Total energy deposit.
//     4) Procees defining end of step.
//     5) Global time (from start of event) at pre- amd post-step.
//
// Contact:
//   Questions and comments to this code should be sent to
//     Katsuya Amako  (e-mail: Katsuya.Amako@kek.jp)
//     Makoto  Asai   (e-mail: asai@kekvax.kek.jp)
//     Takashi Sasaki (e-mail: Takashi.Sasaki@kek.jp)
//   and on the extended code to:
//     John Allison   (e-mail: John.Allison@manchester.ac.uk)
//     Joseph Perl    (e-mail: perl@slac.stanford.edu)
//
// ---------------------------------------------------------------

#ifndef G4RICHTRAJECTORYPOINT_HH
#define G4RICHTRAJECTORYPOINT_HH

#include "G4TrajectoryPoint.hh"

#include "G4ThreeVector.hh"
#include <vector>

class G4Track;
class G4Step;
class G4VProcess;

class G4RichTrajectoryPoint : public G4TrajectoryPoint
{

public: // without description

  // Constructor/Destructor
  G4RichTrajectoryPoint();
  G4RichTrajectoryPoint(const G4Track*);  // For first point.
  G4RichTrajectoryPoint(const G4Step*);   // For subsequent points.
  G4RichTrajectoryPoint(const G4RichTrajectoryPoint &right);
  virtual ~G4RichTrajectoryPoint();

  // Get/Set functions
  const std::vector<G4ThreeVector>* GetAuxiliaryPoints() const
   { return fpAuxiliaryPointVector; }

  // Operators
  inline void *operator new(size_t);
  inline void operator delete(void *aRichTrajectoryPoint);
  inline int operator==(const G4RichTrajectoryPoint& right) const
  { return (this==&right); }

  // Get methods for HepRep style attributes
  virtual const std::map<G4String,G4AttDef>* GetAttDefs() const;
  virtual std::vector<G4AttValue>* CreateAttValues() const;

private:

  // Extended member data
  std::vector<G4ThreeVector>* fpAuxiliaryPointVector;
  G4double fTotEDep;
  const G4VProcess* fpProcess;
  G4double fPreStepPointGlobalTime;
  G4double fPostStepPointGlobalTime;
};

#if defined G4TRACKING_ALLOC_EXPORT
extern G4DLLEXPORT G4Allocator<G4RichTrajectoryPoint>
aRichTrajectoryPointAllocator;
#else
extern G4DLLIMPORT G4Allocator<G4RichTrajectoryPoint>
aRichTrajectoryPointAllocator;
#endif

inline void* G4RichTrajectoryPoint::operator new(size_t)
{
  void *aRichTrajectoryPoint;
  aRichTrajectoryPoint =
    (void *) aRichTrajectoryPointAllocator.MallocSingle();
  return aRichTrajectoryPoint;
}

inline void G4RichTrajectoryPoint::operator delete
(void *aRichTrajectoryPoint)
{
  aRichTrajectoryPointAllocator.FreeSingle
    ((G4RichTrajectoryPoint *) aRichTrajectoryPoint);
}

#endif

