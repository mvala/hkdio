/// \file AnalyseIO.C
/// \brief Analysis macro IO data driven
///

#if defined(__MAKECINT__) || defined(__MAKECLING__)
#include <TChain.h>
#include <HkAnalysisSelector.h>
#endif
void AnalyseIO(const char *fname = "hk.root", Long64_t nEvents = 0,
               Long64_t idStart = 0) {
  TChain *ch = new TChain("hkTree");
  ch->AddFile(fname);

  HkAnalysisSelectorIO *sel = new HkAnalysisSelectorIO();
  if (nEvents)
    ch->Process(sel, "", nEvents);
  else
    ch->Process(sel);
}
