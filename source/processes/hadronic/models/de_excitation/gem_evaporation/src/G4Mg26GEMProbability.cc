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
// $Id: G4Mg26GEMProbability.cc,v 1.2 2003/11/03 17:53:04 hpw Exp $
// GEANT4 tag $Name: geant4-07-00-cand-01 $
//
// Hadronic Process: Nuclear De-excitations
// by V. Lara (Nov 1999)
//


#include "G4Mg26GEMProbability.hh"

G4Mg26GEMProbability::G4Mg26GEMProbability() :
  G4GEMProbability(26,12,0.0) // A,Z,Spin
{

    ExcitEnergies.push_back(1808.68*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(485.0e-3*picosecond);

    ExcitEnergies.push_back(2938.36*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(139.0e-3*picosecond);

    ExcitEnergies.push_back(3588.3*keV);
    ExcitSpins.push_back(0.0);
    ExcitLifetimes.push_back(6.6e-6*picosecond);

    ExcitEnergies.push_back(3940.5*keV);
    ExcitSpins.push_back(3.0);
    ExcitLifetimes.push_back(6.2e-5*picosecond);

    ExcitEnergies.push_back(4318.4*keV);
    ExcitSpins.push_back(4.0);
    ExcitLifetimes.push_back(201.0e-3*picosecond);

    ExcitEnergies.push_back(4331.9*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(55.0e-3*picosecond);

    ExcitEnergies.push_back(4349.8*keV);
    ExcitSpins.push_back(3.0);
    ExcitLifetimes.push_back(104.0e-3*picosecond);

    ExcitEnergies.push_back(4834.3*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(35.0e-3*picosecond);

    ExcitEnergies.push_back(4900.3*keV);
    ExcitSpins.push_back(4.0);
    ExcitLifetimes.push_back(49.0e-3*picosecond);

    ExcitEnergies.push_back(4972.2*keV);
    ExcitSpins.push_back(0.0);
    ExcitLifetimes.push_back(444.0e-3*picosecond);

    ExcitEnergies.push_back(5290.8*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(69.0e-3*picosecond);

    ExcitEnergies.push_back(5473.9*keV);
    ExcitSpins.push_back(4.0);
    ExcitLifetimes.push_back(24.0e-3*picosecond);

    ExcitEnergies.push_back(5690.1*keV);
    ExcitSpins.push_back(1.0);
    ExcitLifetimes.push_back(49.0e-3*picosecond);

    ExcitEnergies.push_back(5715.5*keV);
    ExcitSpins.push_back(4.0);
    ExcitLifetimes.push_back(94.0e-3*picosecond);

    ExcitEnergies.push_back(6256.0*keV);
    ExcitSpins.push_back(0.0);
    ExcitLifetimes.push_back(52.0e-3*picosecond);

    ExcitEnergies.push_back(6621.0*keV);
    ExcitSpins.push_back(3.0);
    ExcitLifetimes.push_back(69.0e-3*picosecond);

    ExcitEnergies.push_back(6744.0*keV);
    ExcitSpins.push_back(2.0);
    ExcitLifetimes.push_back(55.0e-3*picosecond);

    ExcitEnergies.push_back(6877.7*keV);
    ExcitSpins.push_back(3.0);
    ExcitLifetimes.push_back(83.0e-3*picosecond);

}


G4Mg26GEMProbability::G4Mg26GEMProbability(const G4Mg26GEMProbability &) : G4GEMProbability()
{
  throw G4HadronicException(__FILE__, __LINE__, "G4Mg26GEMProbability::copy_constructor meant to not be accessable");
}




const G4Mg26GEMProbability & G4Mg26GEMProbability::
operator=(const G4Mg26GEMProbability &)
{
  throw G4HadronicException(__FILE__, __LINE__, "G4Mg26GEMProbability::operator= meant to not be accessable");
  return *this;
}


G4bool G4Mg26GEMProbability::operator==(const G4Mg26GEMProbability &) const
{
  return false;
}

G4bool G4Mg26GEMProbability::operator!=(const G4Mg26GEMProbability &) const
{
  return true;
}


