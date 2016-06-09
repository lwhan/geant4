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
// $Id: SoG4MarkerSet.h,v 1.2 2006/12/13 15:49:53 gunter Exp $
// GEANT4 tag $Name: geant4-09-01 $
//
// John Allison  26th October 2006
// Extended SoMarkerSet to include G4Atts.

#ifndef SoG4MarkerSet_h
#define SoG4MarkerSet_h

// Inheritance :
#include <HEPVis/nodes/SoMarkerSet.h>
#include "G4AttHolder.hh"

class SoG4MarkerSet: public SoMarkerSet, public G4AttHolder {};

#endif  //SoG4MarkerSet_h
