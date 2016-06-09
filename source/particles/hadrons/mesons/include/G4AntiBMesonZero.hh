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
// $Id: G4AntiBMesonZero.hh,v 1.11 2006/06/29 19:18:06 gunter Exp $
// GEANT4 tag $Name: geant4-09-01 $
//
// 
// ------------------------------------------------------------
//      GEANT 4 class header file
//
//
//      Created,             Hisaya Kurashige, 15 June 1997
// **********************************************************************
//  New implementation as a utility class  M.Asai, 26 July 2004
// ----------------------------------------------------------------

#ifndef G4AntiBMesonZero_h
#define G4AntiBMesonZero_h 1

#include "globals.hh"
#include "G4ios.hh"
#include "G4ParticleDefinition.hh"

// ######################################################################
// ###                         AntiBMesonZero                         ###
// ######################################################################

class G4AntiBMesonZero : public G4ParticleDefinition
{
 private:
   static G4AntiBMesonZero* theInstance;
   G4AntiBMesonZero(){}
   ~G4AntiBMesonZero(){}

 public:
   static G4AntiBMesonZero* Definition();
   static G4AntiBMesonZero* AntiBMesonZeroDefinition();
   static G4AntiBMesonZero* AntiBMesonZero();
};

#endif
