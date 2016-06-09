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
// $Id: G4Mg23GEMChannel.hh,v 1.3 2006/06/29 20:17:01 gunter Exp $
// GEANT4 tag $Name: geant4-09-01 $
//
// Hadronic Process: Nuclear De-excitations
// by V. Lara (Sept. 2001)
//


#ifndef G4Mg23GEMChannel_h
#define G4Mg23GEMChannel_h 1

#include "G4GEMChannel.hh"
#include "G4Mg23GEMCoulombBarrier.hh"
#include "G4Mg23GEMProbability.hh"

class G4Mg23GEMChannel : public G4GEMChannel
{
public:
  // only available constructor
  G4Mg23GEMChannel() : G4GEMChannel(23,12,"Mg23",
				   &theEvaporationProbability,
				   &theCoulombBarrier)
  {
    theEvaporationProbability.SetCoulomBarrier(&theCoulombBarrier);
  }
  
  // destructor
  ~G4Mg23GEMChannel() {};
  
private:
  const G4Mg23GEMChannel & operator=(const G4Mg23GEMChannel & right);  
    
  G4Mg23GEMChannel(const G4Mg23GEMChannel & right);
  
public:
  G4bool operator==(const G4Mg23GEMChannel & right) const;
  G4bool operator!=(const G4Mg23GEMChannel & right) const;
    
private:
  
  G4Mg23GEMCoulombBarrier theCoulombBarrier;
	
  G4Mg23GEMProbability theEvaporationProbability;
  
};
#endif
