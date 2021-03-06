#ifndef STUBTRANSLATOR_H
#define STUBTRANSLATOR_H

/*****************************



 ******************************/

//Include std C++
#include <iostream>
#include <vector>
using namespace std;

// ROOT stuff
#include "TMath.h"
#include "TTree.h"
#include "TFile.h"

#include "StubExtractor.h"

class StubTranslator
{
 public:
  StubTranslator();

  ~StubTranslator();
  
  //Selection

  void do_translation(StubExtractor *st);

  void reset();
  void fillTree();

 private:

  TTree* m_tree_L1TrackTrigger;
 
  int m_stub;

  // Size of the following vectors is m_stub
  std::vector<float>  *m_stub_ptGEN;  // pt generated of stub i (in GeV/c)
  std::vector<float>  *m_stub_etaGEN; // eta generated of stub i (in GeV/c)
  std::vector<int>    *m_stub_modid;  // 
  std::vector<float>  *m_stub_strip;  // strip of stub i (innermost module value) ///new int -> float
};

#endif 
