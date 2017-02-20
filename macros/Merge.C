#include <TString.h>
void Merge(const char *input = "hists.txt",
           const char *outfile = "HistMerged.root") {
  TFileMerger *m = new TFileMerger(kFALSE);
  std::ifstream infile(input);
  std::string line;
  while (std::getline(infile, line)) {
    Printf("Adding file %s ...", line.data());
    m->AddFile(line.data());
  }
  m->OutputFile(outfile);
  m->Merge();

  TFile *f = TFile::Open(outfile, "READ");

  TH1D *hPx = dynamic_cast<TH1D *>(f->Get("hPx"));
  TH1D *hPy = dynamic_cast<TH1D *>(f->Get("hPy"));
  TH1D *hPz = dynamic_cast<TH1D *>(f->Get("hPz"));
  TH2D *hPxPy = dynamic_cast<TH2D *>(f->Get("hPxPy"));

  if ((hPx) && (hPy) && (hPz) && (hPxPy)) {
    TCanvas *c = new TCanvas("cP", "Momentum distributions");
    c->Divide(2, 2);
    c->cd(1);
    hPx->Draw();
    c->cd(2);
    hPy->Draw();
    c->cd(3);
    hPz->Draw();
    c->cd(4);
    hPxPy->Draw();
  }
}