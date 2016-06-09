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
// $Id: G4PSTrackLength3D.hh,v 1.2 2007/08/28 10:11:29 taso Exp $
// GEANT4 tag $Name: geant4-09-01 $
//

#ifndef G4PSTrackLength3D_h
#define G4PSTrackLength3D_h 1

#include "G4PSTrackLength.hh"

////////////////////////////////////////////////////////////////////////////////
// (Description)
//   This is a primitive scorer class for scoring track length.
// 
//
// Created: 2008-08-14  Tsukasa ASO
// 
///////////////////////////////////////////////////////////////////////////////

class G4PSTrackLength3D : public G4PSTrackLength
{
 
 public: // with description
      G4PSTrackLength3D(G4String name, 
		     G4int ni=1,G4int nj=1, G4int nk=1,
		     G4int depi=2, G4int depj=1, G4int depk=0);

      virtual ~G4PSTrackLength3D();

  protected: // with description
      virtual G4int GetIndex(G4Step*);

  private:
      G4int fDepthi, fDepthj, fDepthk;

};
#endif
