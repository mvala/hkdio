#ifndef HkEvent_cxx
#define HkEvent_cxx

#include "HkTrack.h"
#include <TClonesArray.h>
#include <TObject.h>

///
/// \class HkEvent
///
/// \brief Event object
///	\author Martin Vala <mvala@cern.ch>
///

class HkEvent : public TObject {

public:
  HkEvent();
  HkEvent(Long64_t id, Double_t vx = 0.0, Double_t vy = 0.0, Double_t vz = 0.0);
  virtual ~HkEvent();

  /// \fn Long64_t GetID() const
  /// Event ID
  /// \return event ID
  ///
  /// \fn Double_t GetVx() const
  /// Vertex x component
  /// \return Vx component
  ///
  /// \fn Double_t GetVy() const
  /// Vertex y component
  /// \return Vy component
  ///
  /// \fn Double_t GetVz() const
  /// Vertex z component
  /// \return Vz component
  ///
  /// \fn void SetID(Long64_t id)
  /// \param id Input Evemt ID
  ///
  /// Sets event ID
  ///
  /// \fn void SetVx(Double_t vx)
  /// \param vx Input Vx
  ///
  /// Sets x component of vertex
  /// \fn void SetVy(Double_t vy)
  /// \param vy Input Vy
  ///
  /// Sets y component of vertex
  ///
  /// \fn void SetVz(Double_t vz)
  /// \param vz Input Vz
  ///
  /// Sets z component of vertex
  ///
  /// \fn Long64_t GetNTrack() const
  /// \return number of tracks
  ///
  /// \fn HkTrack *GetTrack(Long64_t id)
  /// \param id ID of track
  /// \return Track with id

  Long64_t GetID() const { return fID; }
  Double_t GetVx() const { return fVx; }
  Double_t GetVy() const { return fVy; }
  Double_t GetVz() const { return fVz; }

  void SetID(Long64_t id) { fID = id; }
  void SetVx(Double_t vx) { fVx = vx; }
  void SetVy(Double_t vy) { fVy = vy; }
  void SetVz(Double_t vz) { fVz = vz; }

  Long64_t GetNTrack() const { return fNTracks; }
  HkTrack *GetTrack(Long64_t id) { return (HkTrack *)fTracks->At(id); }
  HkTrack *AddTrack();

  virtual void Print(Option_t *option = "") const;
  virtual void Clear(Option_t *option = "");

  void BuildVertexRandom();

private:
  Long64_t fID;   ///< ID of event
  Double_t fVx;   ///< Vertex x
  Double_t fVy;   ///< Vertex y
  Double_t fVz;   ///< Vertex z
  Int_t fNTracks; ///< Number of tracks

  /// Array with all tracks
  TClonesArray *fTracks; //->

  // TODO
  /// Copy constructor
  HkEvent(const HkEvent &);            /// not implemented
  HkEvent &operator=(const HkEvent &); /// not implemented

  /// \cond CLASSIMP
  ClassDef(HkEvent, 1);
  /// \endcond
};

#endif
