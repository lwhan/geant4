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
// $Id: G4eBremsstrahlungCMS.cc,v 1.6 2004/11/01 09:57:11 vnivanch Exp $
// GEANT4 tag $Name: geant4-07-00-cand-01 $
//
// -------------------------------------------------------------------
//
// GEANT4 Class file
//
//
// File name:     G4eBremsstrahlungCMS
//
// Author:        Vladimir Ivanchenko
//
// Creation date: 12.09.03
//
// Modifications:
//
// 17-10-03 model variant (V.Ivanchenko)
// 05-04-03 Migrate to ParticleChangeForLoss (V.Ivanchenko) 
// 01-11-04 Migrade to new interfaces to ParticleChange (V.Ivanchenko)
//
// -------------------------------------------------------------------
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "G4eBremsstrahlungCMS.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4eBremsstrahlungCMS::G4eBremsstrahlungCMS(const G4String& name,G4double thresh) 
  : G4eBremsstrahlung(name), gammaThreshold(thresh)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4eBremsstrahlungCMS::~G4eBremsstrahlungCMS()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void G4eBremsstrahlungCMS::SecondariesPostStep( G4VEmModel* model,
                                          const G4MaterialCutsCouple* couple,
                                          const G4DynamicParticle* dp,
                                                G4double& tcut,
                                                G4double& kinEnergy)
{
  G4DynamicParticle* gamma = model->SampleSecondary(couple, dp, tcut, kinEnergy);
  G4double gammaEnergy = gamma->GetKineticEnergy(); 
  kinEnergy -= gammaEnergy;
  G4int nSecond = 1;
  if(gammaEnergy > gammaThreshold) nSecond = 2;
  fParticleChange.SetNumberOfSecondaries(nSecond);
  fParticleChange.AddSecondary(gamma);
  fParticleChange.ProposeLocalEnergyDeposit(0.0);
  if(nSecond == 2) {
    fParticleChange.ProposeTrackStatus(fStopAndKill);
    G4DynamicParticle* el = new G4DynamicParticle(dp->GetDefinition(),
                                                  dp->GetMomentumDirection(),
                                                  kinEnergy);
    fParticleChange.AddSecondary(el);
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void G4eBremsstrahlungCMS::PrintInfoDefinition()
{
  G4eBremsstrahlung::PrintInfoDefinition();
  G4cout << "      Gamma high energy threshold " 
         << gammaThreshold/MeV << " MeV" << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......