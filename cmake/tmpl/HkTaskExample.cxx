#include "HkTaskExample.h"

/// \cond CLASSIMP
ClassImp(HkTaskExample);
/// \endcond
HkTaskExample::HkTaskExample(const char *name, const char *title)
    : HkTask(name, title) {
  ///
  /// Default constructor
  ///
}

HkTaskExample::~HkTaskExample() {
  ///
  /// Destructor
  ///
}

void HkTaskExample::Exec(Option_t * /*option*/) {
  ///
  /// Main function to process resonance study
  ///
}
