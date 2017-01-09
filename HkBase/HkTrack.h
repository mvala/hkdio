#ifndef HkTrack_cxx
#define HkTrack_cxx

#include <TObject.h>

///
/// \class HkTrack
///
/// \brief Track object
///	\author Martin Vala <mvala@cern.ch>
///

class HkTrack : public TObject {

public:
  HkTrack();
  virtual ~HkTrack();

  /// \fn Double_t GetPx() const
  /// Momentum x component
  /// \return Px component
  ///! \fn Double_t GetPy() const
  /// Momentum y component
  /// \return Py component
  ///! \fn Double_t GetPz() const
  /// Momentum z component
  ///\return Pz component
  ///! \fn Int_t GetCharge() const
  /// Charge of track
  ///\return charge
  ///! \fn void SetPx(Double_t px)
  /// \param px Input Px
  /// Sets x component of momentum
  ///! \fn void SetPy(Double_t py)
  /// \param py Input Py
  /// Sets y component of momentum
  ///! \fn void SetPz(Double_t pz)
  /// \param pz Input Pz
  /// Sets z component of momentum
  ///! \fn void SetCharge(Int_t ch)
  /// \param ch Input charge
  /// Sets charge

  Double_t GetPx() const { return fPx; }
  Double_t GetPy() const { return fPy; }
  Double_t GetPz() const { return fPz; }
  Short_t GetCharge() const { return fCharge; }

  void SetPx(Double_t px) { fPx = px; }
  void SetPy(Double_t py) { fPy = py; }
  void SetPz(Double_t pz) { fPz = pz; }
  void SetP(Double_t *p);
  void SetCharge(Short_t ch) { fCharge = ch; }

  virtual void Print(Option_t *option = "") const;
  virtual void Clear(Option_t *option = "");

  void BuildRandom();

private:
  Double_t fPx;    ///< Momentum x
  Double_t fPy;    ///< Momentum y
  Double_t fPz;    ///< Momentum z
  Short_t fCharge; ///< Charge

  // TODO
  /// Copy constructor
  HkTrack(const HkTrack &);            /// not implemented
  HkTrack &operator=(const HkTrack &); /// not implemented

  /// \cond CLASSIMP
  ClassDef(HkTrack, 1);
  /// \endcond
};

#endif
