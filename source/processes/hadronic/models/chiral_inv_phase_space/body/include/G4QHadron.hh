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
// $Id: G4QHadron.hh,v 1.35 2007/08/28 15:42:32 mkossov Exp $
// GEANT4 tag $Name: geant4-09-01 $
//
//      ---------------- G4QHadron ----------------
//             by Mikhail Kossov, Sept 1999.
//  class header for Hadrons generated by the CHIPS Model
// ------------------------------------------------------

#ifndef G4QHadron_h
#define G4QHadron_h 1

#include "globals.hh"
#include "G4ThreeVector.hh"
#include "G4LorentzVector.hh"
#include "Randomize.hh"
#include "G4QParticle.hh"
#include "G4QPartonVector.hh"
#include <deque>

class G4QHadron
{
public:
  // Constructors
  G4QHadron();                                      // Default Constructor
  G4QHadron(G4LorentzVector p);                     // Kinematical Constructor
  G4QHadron(G4int PDGcode, G4LorentzVector p=G4LorentzVector(0.,0.,0.,0.));//CHIPS-W Hadron
  G4QHadron(G4QPDGCode QPDG, G4LorentzVector p=G4LorentzVector(0.,0.,0.,0.));//CHIPS-W Had.
  G4QHadron(G4QContent QC, G4LorentzVector p=G4LorentzVector(0.,0.,0.,0.));//QC C-W Hadron
  G4QHadron(G4int PDG, G4double m, G4QContent QC); // Constructor for Chipolino or Quasmon
  G4QHadron(G4QPDGCode QPDG, G4double m, G4QContent QC);// Constr. for Chipolino or Quasmon
  G4QHadron(G4int PDG, G4LorentzVector p, G4QContent QC);// Constr for Chipolino or Quasmon
  G4QHadron(G4QPDGCode QPDG, G4LorentzVector p, G4QContent QC);// Con. for Chipo or Quasmon
  G4QHadron(G4QParticle* pPart, G4double maxM);     // Constructor for Res with RANDOM mass
  G4QHadron(const G4QHadron& right);                // Copy constructor by object
  G4QHadron(const G4QHadron* right);                // Copy constructor by pointer
  G4QHadron(const G4QHadron* right, G4int ColC, G4ThreeVector Pos, G4LorentzVector Mom);
  virtual ~G4QHadron();                             // Destructor
  // Operators
  const G4QHadron& operator=(const G4QHadron& right);
  G4bool           operator==(const G4QHadron& right) const;
  G4bool           operator!=(const G4QHadron& right) const;
  // Selectors
  G4int                 GetPDGCode()      const;    // Get PDG code of the Hadron
  G4int                 GetQCode()        const;    // Get Q code of the Hadron
  G4QPDGCode            GetQPDG()         const;    // Get QPDG of the Hadron
  G4double              GetSpin()         const{return .5*(GetPDGCode()%10-1);}
  G4LorentzVector       Get4Momentum()    const;    // Get 4-mom of the Hadron
  G4QContent            GetQC()           const;    // Get private quark content
  G4double              GetMass()         const;    // Get a mass of the Hadron
  G4double              GetMass2()        const;    // Get an m^2 value for the Hadron
  G4double              GetWidth()        const;    // Get Width of Hadron 
  G4int                 GetNFragments()   const;    // Get a#of Fragments of this Hadron
  G4int                 GetCharge()       const;    // Get Charge of the Hadron
  G4int                 GetStrangeness()  const;    // Get Strangeness of the Hadron
  G4int                 GetBaryonNumber() const;    // Get Baryon Number of the Hadron
  const G4ThreeVector&  GetPosition()     const;    // Get hadron coordinates
  G4int                 GetSoftCollisionCount();    // Get QGS Counter of collisions
  G4bool                IsSplit() {return isSplit;} // Check that hadron has been split
  G4double              GetBindingEnergy() {return bindE;}// Returns binding E in NucMatter
  G4double              GetFormationTime() {return formTime;} // Returns formation time

  // Modifiers
  void SetQPDG(const G4QPDGCode& QPDG);             // Set QPDG of the Hadron
  void Set4Momentum(const G4LorentzVector& aMom);   // Set 4-mom of the Hadron
  void SetQC(const G4QContent& newQC);              // Set new private quark content
  void SetNFragments(const G4int& nf);              // Set a#of Fragments of this Hadron
  void NegPDGCode();                                // Change a sign of the PDG code
  void MakeAntiHadron();                            // Make AntiHadron of this Hadron
  void SetPosition(const G4ThreeVector& aPosition); // Set coordinates of hadron position
  void IncrementCollisionCount(G4int aCount);       // Increnment counter of collisions
  void SetCollisionCount(G4int aCount);             // Set counter of QGSM collisions
  void Splitting() {isSplit = true;}                // Put Up a flag that splitting is done
  void SplitUp();                                   // Make QGSM String Splitting of Hadron
  G4QParton* GetNextParton();                       // Next Parton in a string
  G4QParton* GetNextAntiParton();                   // Next Anti-Parton in a string
  void SetBindingEnergy(G4double aBindE){bindE=aBindE;}// Set Binding E in Nuclear Matter
  void Boost(const G4LorentzVector& theBoost);      // Boosts hadron's 4-Momentum using 4M
  void Boost(const G4ThreeVector& B){theMomentum.boost(B);} // Boosts 4-Momentum using v/c
  void SetFormationTime(G4double fT){formTime=fT;}  // Defines formationTime for the Hadron

  // General
  G4double RandomizeMass(G4QParticle* pPart, G4double maxM); // Randomize a mass value
  G4bool TestRealNeutral();
  G4bool DecayIn2(G4LorentzVector& f4Mom, G4LorentzVector& s4Mom);
  G4bool CorMDecayIn2(G4double corM, G4LorentzVector& fr4Mom);// This(newMass corM)+fr4Mom
  G4bool CorEDecayIn2(G4double corE, G4LorentzVector& fr4Mom);// This(E+=cE,P)+f(fE-=cE,fP)
  G4bool RelDecayIn2(G4LorentzVector& f4Mom, G4LorentzVector& s4Mom, G4LorentzVector& dir,
                     G4double maxCost = 1., G4double minCost = -1.);
  G4bool CopDecayIn2(G4LorentzVector& f4Mom, G4LorentzVector& s4Mom, G4LorentzVector& dir,
                     G4double cop);
  G4bool DecayIn3(G4LorentzVector& f4Mom, G4LorentzVector& s4Mom, G4LorentzVector& t4Mom);
  G4bool RelDecayIn3(G4LorentzVector& fh4M, G4LorentzVector& sh4M, G4LorentzVector& th4Mom,
                     G4LorentzVector& dir, G4double maxCost = 1., G4double minCost = -1.);
  G4bool CopDecayIn3(G4LorentzVector& fh4M, G4LorentzVector& sh4M, G4LorentzVector& th4Mom,
                     G4LorentzVector& dir, G4double cosp);
  void   Init3D();                         // Initializes 3D nucleus with (Pos,4M)nucleons

private:
  // Private methods
  void DefineQC(G4int PDGCode);
  G4QParton* BuildSeaQuark(G4bool isAntiQuark, G4int aPDGCode);
  G4double SampleX(G4double anXmin, G4int nSea, G4int theTotalSea, G4double aBeta);
  void GetValenceQuarkFlavors(G4QParton* &Part1,G4QParton* &Part2);
  G4ThreeVector GaussianPt(G4double widthSquare, G4double maxPtSquare);
  G4bool SplitMeson(G4int PDGcode, G4int* aEnd, G4int* bEnd);
  G4bool SplitBaryon(G4int PDGcode, G4int* aEnd, G4int* bEnd);

private:
  // Static Parameters of QGSM Splitting
  static G4double alpha;            // changing rapidity distribution for all
  static G4double beta;             // changing rapidity distribution for projectile region
  static G4double theMinPz;         // Can be from 14 to 140 MeV
  static G4double StrangeSuppress;  // ? M.K.
  static G4double sigmaPt;          // Can be 0
  static G4double widthOfPtSquare;  // ? M.K.
  static G4double minTransverseMass;// ? M.K.
  // Body 
  G4QPDGCode             theQPDG;           // Instance of QPDG for the Hadron
  G4LorentzVector        theMomentum;       // The 4-mom of Hadron
  G4QContent             valQ;              // QC (@@ for Quasmon and Chipolino?)
  G4int                  nFragm;            // 0 - stable, N - decayed in N part's
  // Body of Splitable Hadron and Nuclear Nucleon
  G4ThreeVector          thePosition;       // Coordinates of Hadron position
  G4int                  theCollisionCount; // ?
  G4bool                 isSplit;           // Flag, that splitting was done
  G4bool                 Direction;         // FALSE=target, TRUE=projectile
  std::deque<G4QParton*> Color;             // container for quarks & anti-diquarks
  std::deque<G4QParton*> AntiColor;         // container for anti-quarks & diquarks
  G4double               bindE;             // Binding energy in nuclear matter
  G4double               formTime;          // Formation time for the hadron
};

typedef std::pair<G4QHadron*, G4QHadron*> G4QHadronPair;

inline G4bool G4QHadron::operator==(const G4QHadron &rhs) const {return this==&rhs;}
inline G4bool G4QHadron::operator!=(const G4QHadron &rhs) const {return this!=&rhs;}
 
inline G4int           G4QHadron::GetPDGCode()      const  {return theQPDG.GetPDGCode();}
inline G4int           G4QHadron::GetQCode()        const  {return theQPDG.GetQCode();}
inline G4QPDGCode      G4QHadron::GetQPDG()         const  {return theQPDG;}
inline G4QContent      G4QHadron::GetQC()           const  {return valQ;}
inline G4LorentzVector G4QHadron::Get4Momentum()    const  {return theMomentum;}
inline G4int           G4QHadron::GetNFragments()   const  {return nFragm;}
//@@ This is an example how to make other inline selectors for the 4-Momentum of the Hadron
inline G4double        G4QHadron::GetMass()         const  {return theMomentum.m();}
inline G4double        G4QHadron::GetMass2()        const  {return theMomentum.m2();}
//@@ This is an example how to make other inline selectors for the Hadron
inline G4int           G4QHadron::GetCharge()       const  {return valQ.GetCharge();}
inline G4int           G4QHadron::GetStrangeness()  const  {return valQ.GetStrangeness();}
inline G4int           G4QHadron::GetBaryonNumber() const  {return valQ.GetBaryonNumber();}
inline const G4ThreeVector& G4QHadron::GetPosition() const {return thePosition;}
inline G4int           G4QHadron::GetSoftCollisionCount()  {return theCollisionCount;}

inline void            G4QHadron::MakeAntiHadron()    {if(TestRealNeutral()) NegPDGCode();}
inline void   G4QHadron::SetQC(const G4QContent& newQC)             {valQ=newQC;}
inline void   G4QHadron::Set4Momentum(const G4LorentzVector& aMom)  {theMomentum=aMom;}
inline void   G4QHadron::SetNFragments(const G4int& nf)             {nFragm=nf;}
inline void   G4QHadron::SetPosition(const G4ThreeVector& position) {thePosition=position;}
inline void   G4QHadron::IncrementCollisionCount(G4int aCount) {theCollisionCount+=aCount;}
inline void   G4QHadron::SetCollisionCount(G4int aCount)       {theCollisionCount =aCount;}

inline void   G4QHadron::NegPDGCode()                  {theQPDG.NegPDGCode(); valQ.Anti();}
inline G4bool G4QHadron::TestRealNeutral()             { return theQPDG.TestRealNeutral();}

inline G4QParton* G4QHadron::GetNextParton()
{
   if(Color.size()==0) return 0;
   G4QParton* result = Color.back();
   Color.pop_back();
   return result;
}

inline G4QParton* G4QHadron::GetNextAntiParton()
{
   if(AntiColor.size() == 0) return 0;
   G4QParton* result = AntiColor.front();
   AntiColor.pop_front();
   return result;
}
#endif

