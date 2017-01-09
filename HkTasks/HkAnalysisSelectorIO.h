#ifndef HkAnalysisSelectorIO_H
#define HkAnalysisSelectorIO_H

#include <TH1D.h>
#include <TH2D.h>
#include <TSelector.h>

class TTree;
class HkEvent;

///
/// \class HkAnalysisSelectorIO
///
/// \brief IO driven selector
///	\author Martin Vala <mvala@cern.ch>
///

class HkAnalysisSelectorIO : public TSelector {

public:
  HkAnalysisSelectorIO(TTree *tree = 0);
  virtual ~HkAnalysisSelectorIO();

  /// Returns selector version
  virtual Int_t Version() const { return 2; }
  virtual void Begin(TTree * /*tree*/);
  virtual void SlaveBegin(TTree *tree);
  virtual void Init(TTree *tree);
  virtual Bool_t Notify();
  virtual Bool_t Process(Long64_t entry);
  virtual Int_t GetEntry(Long64_t entry, Int_t getall = 0);
  virtual void SlaveTerminate();
  virtual void Terminate();

private:
  /// Pointer to the analyzed TTree or TChain
  TTree *fChain; //!

  HkEvent *fEvent; ///< Current Event
  TH1D *fHistPx;   ///< px distribution
  TH1D *fHistPy;   ///< py distribution
  TH1D *fHistPz;   ///< pz distribution
  TH2D *fHistPxPy; ///< px vs py distribution

  /// \cond CLASSIMP
  ClassDef(HkAnalysisSelectorIO, 1);
  /// \endcond
};

#endif
