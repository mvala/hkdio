#include "HkEvent.h"
#include "HkTask.h"
#include <TCanvas.h>
#include <TFile.h>
#include <TTree.h>

#include "HkAnalysisSelector.h"

/// \cond CLASSIMP
ClassImp(HkAnalysisSelector);
/// \endcond

HkAnalysisSelector::HkAnalysisSelector(TTree * /*tree*/)
    : TSelector(), fChain(0), fEvent(0), fTaskMgr(0) {
  ///
  /// Default constructor
  ///
}

HkAnalysisSelector::~HkAnalysisSelector() {
  ///
  /// Destructor
  ///
  delete fEvent;
}

void HkAnalysisSelector::Init(TTree *tree) {
  ///
  /// Intialize tree
  ///
  if (!tree)
    return;
  fChain = tree;
  fEvent = new HkEvent(0);

  fChain->SetBranchAddress("hkEvent", &fEvent);
  if (fTaskMgr)
    fTaskMgr->GetOutput()->Add(fEvent);
}

Bool_t HkAnalysisSelector::Notify() {
  ///
  /// Notify is called when file is changed
  ///
  if (fChain->GetCurrentFile())
    Printf("File : %s", fChain->GetCurrentFile()->GetName());
  return kTRUE;
}

void HkAnalysisSelector::Begin(TTree * /*tree*/) {
  ///
  /// First user Function called on client
  ///
}

void HkAnalysisSelector::SlaveBegin(TTree * /*tree*/) {
  ///
  /// First user Function called on proof worker
  ///

  TString option = GetOption();

  if (fTaskMgr)
    fTaskMgr->Init("");
}

Bool_t HkAnalysisSelector::Process(Long64_t entry) {
  ///
  /// Process event with ID=entry
  ///

  GetEntry(entry);

  if (entry % 1 == 0)
    Printf("Event %lld ID=%lld nTracks=%lld", entry, fEvent->GetID(),
           fEvent->GetNTrack());

  if (fTaskMgr)
    fTaskMgr->ExecuteTask("");

  return kTRUE;
}

void HkAnalysisSelector::SlaveTerminate() {
  ///
  /// Last user Function called on proof worker
  ///
  if (fTaskMgr)
    fTaskMgr->Finish("");
}

void HkAnalysisSelector::Terminate() {
  ///
  /// Last user Function called on client
  ///
}

Int_t HkAnalysisSelector::GetEntry(Long64_t entry, Int_t getall) {
  ///
  /// Gets entry
  ///
  return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0;
}
