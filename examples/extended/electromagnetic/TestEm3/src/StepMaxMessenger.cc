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
// $Id: StepMaxMessenger.cc,v 1.3 2006/06/29 16:53:21 gunter Exp $
// GEANT4 tag $Name: geant4-09-01 $
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "StepMaxMessenger.hh"

#include "StepMax.hh"
#include "G4UIdirectory.hh"
#include "G4UIcommand.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

StepMaxMessenger::StepMaxMessenger(StepMax* stepM)
:stepMax(stepM)
{
  StepMaxDir = new G4UIdirectory("/testem/stepMax/");
  StepMaxDir->SetGuidance("histograms control");
   
  StepMaxCmd = new G4UIcommand("/testem/stepMax/absorber",this);
  StepMaxCmd->SetGuidance("Set max allowed step length in absorber k");
  //
  G4UIparameter* k = new G4UIparameter("k",'i',false);
  k->SetGuidance("absorber number : from 1 to MaxHisto-1");
  k->SetParameterRange("k>0");
  StepMaxCmd->SetParameter(k);
  //    
  G4UIparameter* sMax = new G4UIparameter("sMax",'d',false);
  sMax->SetGuidance("stepMax, expressed in choosen unit");
  sMax->SetParameterRange("sMax>0.");
  StepMaxCmd->SetParameter(sMax);
  //    
  G4UIparameter* unit = new G4UIparameter("unit",'s',false);
  StepMaxCmd->SetParameter(unit);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

StepMaxMessenger::~StepMaxMessenger()
{
  delete StepMaxCmd;
  delete StepMaxDir;  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void StepMaxMessenger::SetNewValue(G4UIcommand* command, G4String newValues)
{ 
  if (command == StepMaxCmd)
   { G4int k; G4double sMax; 
     G4String unts;
     std::istringstream is(newValues);
     is >> k >> sMax >> unts;
     G4String unit = unts;
     G4double vUnit = G4UIcommand::ValueOf(unit);  
     stepMax->SetStepMax(k,sMax*vUnit);
   }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
