#ifndef SHarper_SHNtupliser_SHNtupliser_h
#define SHarper_SHNtupliser_SHNtupliser_h



// Description: Converts a edm::Event to a heep::Event which is then converted to a SHEvent and written to a TTree

// Implementation:
//   heep::Event in HEEPAnalyzer does all the heavy lifting, all the construction of quantities of the SHEvent is done there
//   all the functions in this package do is translate this information to the SH objects
//   it is a design decision that *no* calculation of variables is done here, everything accessible in a SHEvent must be accessable
//   in a heep::Event, if we need something new, heep::Event is extended
//   As a bonus, the analyzer will optionally write out the Ecal and Hcal geometries to the file. In the future, other information
//   may also be written out
//   The one exception to information not being in heep::Event is information internal to my ntuples (such as datasetCode,eventWeight, isMC) 
 
//
// Original Author:  S. Harper
//         Created: Tues Sep 16 2008



#include "SHarper/SHNtupliser/interface/SHEventHelper.h"

#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "SHarper/HEEPAnalyzer/interface/HEEPEventHelper.h"
#include "SHarper/HEEPAnalyzer/interface/HEEPEvent.h"

#include <string>

namespace edm {
  class ParameterSet;
  class Event;
  class EventSetup;
}

class SHEvent;
class TTree;
class TFile;


class SHNtupliser : public edm::EDAnalyzer {

private:
  heep::EventHelper evtHelper_; //this is our magic class where all the nastyness is contained
  heep::Event heepEvt_;

  SHEventHelper shEvtHelper_;

  SHEvent* shEvt_; //pointer because thats what root likes, we own it
  TTree* evtTree_; //the outFile owns it
  TFile* outFile_; //we own it

  std::string outputFilename_;
  int nrTot_;
  int nrPass_;

  bool initGeom_;

 bool outputGeom_; //write out geom to file
  float minEtToPassEvent_;

  // float oldSigmaIEtaIEta_,newSigmaIEtaIEta_,affectedByCaloNavBug_,scNrgy_,scEta_,scPhi_,scEt_;
  //TTree* scTree_;
  //disabling copy and assignment 
  //I cant think of a reason why I would want to copy this class and its complicated to do right due to TTree
private:
  SHNtupliser(const SHNtupliser& rhs){}
  SHNtupliser& operator=(const SHNtupliser& rhs){return *this;}

public:
  explicit SHNtupliser(const edm::ParameterSet& iPara);
  virtual ~SHNtupliser();
  
private:
  virtual void beginJob() ;
  virtual void beginRun(const edm::Run& run,const edm::EventSetup& iSetup);
  virtual void analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup);
  virtual void endJob() ;
  
  

};

#endif