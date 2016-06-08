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
// $Id: G4MassImportanceSampler.cc,v 1.1 2002/05/31 10:16:02 dressel Exp $
// GEANT4 tag $Name: geant4-04-01 $
//
// ----------------------------------------------------------------------
// GEANT 4 class source file
//
// G4MassImportanceSampler.cc
//
// ----------------------------------------------------------------------

#include "G4MassImportanceSampler.hh"
#include "G4MassImportanceProcess.hh"
#include "G4ProcessPlacer.hh"
#include "G4ImportanceAlgorithm.hh"


G4MassImportanceSampler::
G4MassImportanceSampler(G4VIStore &aIstore,
			const G4String &particlename,
			const G4VImportanceAlgorithm *algorithm)
 : fIStore(aIstore),
   fParticleName(particlename),
   fMassImportanceProcess(0),
   fCreatedAlgorithm( ( ! algorithm) ),
   fAlgorithm(( (fCreatedAlgorithm) ? 
		new G4ImportanceAlgorithm : algorithm))
{}

G4MassImportanceSampler::~G4MassImportanceSampler()
{
  if (fMassImportanceProcess) {
    G4ProcessPlacer placer(fParticleName);
    placer.RemoveProcess(fMassImportanceProcess);
    delete fMassImportanceProcess;
  }
  if (fCreatedAlgorithm) delete fAlgorithm;
}


G4MassImportanceProcess *G4MassImportanceSampler::CreateMassImportanceProcess()
{
  if (!fMassImportanceProcess) {
    fMassImportanceProcess =
      new G4MassImportanceProcess(*fAlgorithm, fIStore);
  }
  return fMassImportanceProcess;
}

void G4MassImportanceSampler::Initialize()
{
  G4ProcessPlacer placer(fParticleName);
  placer.AddProcessAsSecondDoIt(CreateMassImportanceProcess());
}