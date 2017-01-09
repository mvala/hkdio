#ifndef HkTaskInput_cxx
#define HkTaskInput_cxx

#include <HkTask.h>

///
/// \class HkTaskInput
///
/// \brief Input task
///	\author Martin Vala <mvala@cern.ch>
///

class HkTaskInput : public HkTask {

public:
  HkTaskInput(const char *name = "HkTaskInput",
              const char *title = "HkTaskInput title");
  virtual ~HkTaskInput();

  virtual void Exec(Option_t *option);

private:
  /// \cond CLASSIMP
  ClassDef(HkTaskInput, 1);
  /// \endcond
};

#endif
