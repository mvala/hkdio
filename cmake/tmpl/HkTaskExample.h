#ifndef HkTaskExample_cxx
#define HkTaskExample_cxx

#include <HkTask.h>

///
/// \class HkTaskExample
///
/// \brief Example task
///	\author Martin Vala <mvala@cern.ch>
///

class HkTaskExample : public HkTask {

public:
  HkTaskExample(const char *name = "HkTaskExample",
                const char *title = "HkTaskExample title");
  virtual ~HkTaskExample();

  virtual void Exec(Option_t *option);

private:
  /// \cond CLASSIMP
  ClassDef(HkTaskExample, 1);
  /// \endcond
};

#endif
