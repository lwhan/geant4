//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: ExN07VisManager.hh,v 1.1 2003/03/10 01:43:36 asaim Exp $
// GEANT4 tag $Name: geant4-07-00-cand-01 $
//
// 

#ifndef ExN07VisManager_h
#define ExN07VisManager_h 1

#ifdef G4VIS_USE

#include "G4VisManager.hh"

class ExN07VisManager: public G4VisManager {

public:

  ExN07VisManager ();

private:

  void RegisterGraphicsSystems ();

};


#endif

#endif