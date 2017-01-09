/// \file Analyse.C
/// \brief Analysis macro of task selector
///

#if defined(__MAKECINT__) || defined(__MAKECLING__)
#include <TChain.h>
#include <HkAnalysisSelector.h>
#endif
void Analyse(Int_t nTasks = 10, const char *fname = "hk.root",
             Long64_t nEvents = kMaxLong64, Long64_t idStart = 0,
             Long64_t nSkip = 1, Bool_t eqTasks = kTRUE) {
  TChain *ch = new TChain("hkTree");
  ch->AddFile(fname);

  HkAnalysisSelector *sel = new HkAnalysisSelector();

  HkTaskInput *tm = new HkTaskInput("hkTaskMgr", "Hk task manager");

  HkTaskTbd *tTbd;
  Int_t nskip;
  for (Int_t i = 0; i < nTasks; i++) {
    tTbd = new HkTaskTbd(TString::Format("rsn%05d", i).Data());
    if (eqTasks)
      nskip = nSkip;
    else
      nskip = i % nSkip + 1;
    tTbd->SetNSkip(nskip);
    Printf("Task name=%s nSkip=%d", tTbd->GetName(), nskip);
    tm->Add(tTbd);
  }

  sel->SetTaskManager(tm);
  ch->Process(sel, "", nEvents);

  gROOT->GetListOfBrowsables()->Add(tm, "hk");
}
