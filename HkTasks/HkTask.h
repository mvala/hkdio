#ifndef HkTask_cxx
#define HkTask_cxx

#include <TTask.h>

///
/// \class HkTask
///
/// \brief Base task
///	\author Martin Vala <mvala@cern.ch>
///

class HkTask : public TTask {

public:
  HkTask();
  HkTask(const char *name, const char *title = "");
  virtual ~HkTask();

  /// \fn virtual void Add(TTask *task)
  /// Adds task
  /// \param task Task to add
  ///
  /// \fn virtual void Init(Option_t *option)
  /// Init function
  /// \param option Inti option
  ///
  /// \fn virtual void Exec(Option_t *option);
  /// User's function
  /// \param option Task option
  ///
  /// \fn virtual void ExecPost(Option_t *option);
  /// User's function executed after all sub tasks
  /// \param option Task option
  ////
  /// \fn virtual void Finish(Option_t *option);
  /// User's function executed after all sub tasks
  /// \param option Task option
  ///
  /// \fn void SetParent(HkTask *task)
  /// Sets parent task
  /// \param task Parent task
  ///
  ///
  /// \fn HkTask *GetParent() const
  /// Returns parent task
  ///
  /// \return Parent task
  ///
  /// \fn TList *GetOutput() const
  /// Returns output list
  ///
  /// \return Output list
  ///
  /// \fn virtual void Browse(TBrowser *b)
  /// Browse elements
  ///
  /// \param b Pointer to browser
  ///
  /// \fn virtual void Export(TDirectory *root)
  /// Export tasks to TDirectory
  ///
  /// \param root Root directory
  ///

  virtual void Add(TTask *task);

  virtual void ExecuteTask(Option_t *option);
  virtual void ExecuteTasks(Option_t *option);

  virtual void Init(Option_t *option);
  virtual void Exec(Option_t *option);
  virtual void ExecPost(Option_t *option);
  virtual void Finish(Option_t *option);

  void SetParent(HkTask *task) { fParent = task; }
  HkTask *GetParent() const { return fParent; }

  TList *GetOutput() const { return fOutput; }

  virtual void Browse(TBrowser *b);

  virtual void Export(TDirectory *root);

protected:
  /// Partent task
  HkTask *fParent; //||
  TList *fOutput;  ///< Output

  /// \cond CLASSIMP
  ClassDef(HkTask, 1);
  /// \endcond
};

#endif
