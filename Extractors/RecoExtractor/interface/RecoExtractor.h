#ifndef RecoExtractor_h
#define RecoExtractor_h

/** \class RecoExtractor
 *  \author by sviret
 */

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/Framework/interface/LuminosityBlock.h"

#include "../interface/PixelExtractor.h"
#include "../interface/MCExtractor.h"
#include "../interface/L1TrackTrigger_analysis.h"
#include "../interface/TkLayout_Translator.h"
#include "../interface/AnalysisSettings.h"

#include "TFile.h"
#include "TRFIOFile.h"

class RecoExtractor : public edm::EDAnalyzer{
 public:
  /// Constructor
  RecoExtractor(const edm::ParameterSet& pset);

  /// Destructor
  virtual ~RecoExtractor(){ }
   int nevent;
  int nevent_tot;

  /// Method called before the event loop
  void beginJob();
  void endJob();

  void beginRun(edm::Run const&, edm::EventSetup const&);
  void endRun(edm::Run const&, edm::EventSetup const&);

  /// Method called once per event
  void analyze(const edm::Event&, const edm::EventSetup& );

  void fillInfo(const edm::Event *event);
  void getInfo(int ievent);
  void initialize();
  void retrieve();
  void doAna();
  


 private:
 
  bool do_fill_;

  bool do_PIX_;
  bool do_MC_;
  bool do_TK_;
  bool do_MATCH_;
  bool do_L1tt_;

  int  nevts_;
  int  skip_;

  edm::InputTag PIX_tag_;  // 
  edm::InputTag MC_tag_;  // 

  //
  // Definition of root-tuple :
  //

  std::string outFilename_;
  std::string inFilename_;

  std::vector<std::string> m_settings_;

  TFile* m_dummyfile;
  TFile* m_infile;
  TFile* m_outfile;


  PixelExtractor*   m_PIX;
  MCExtractor*      m_MC;
  TkLayout_Translator*      m_TK;
  AnalysisSettings*  m_ana_settings;
  L1TrackTrigger_analysis* m_L1TT_analysis;

};


#endif