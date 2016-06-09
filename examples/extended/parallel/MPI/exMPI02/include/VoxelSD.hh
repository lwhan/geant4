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
// $Id: VoxelSD.hh,v 1.1 2007/11/16 14:29:33 kmura Exp $
// $Name: geant4-09-01 $
//
// ====================================================================
//   VoxelSD.hh
//
//                                         2007 Q
// ====================================================================
#ifndef VOXEL_SD_H
#define VOXEL_SD_H

#include "G4VSensitiveDetector.hh"

// ====================================================================
//
// class definition
//
// ====================================================================

class VoxelSD : public G4VSensitiveDetector {

public:
  VoxelSD(const G4String& name);
  ~VoxelSD();

  // virtual methods
  virtual G4bool ProcessHits(G4Step* astep, G4TouchableHistory* rohist);
  virtual void Initialize(G4HCofThisEvent* HCTE);
  virtual void EndOfEvent(G4HCofThisEvent* HCTE);

};

#endif
