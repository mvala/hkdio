R__LOAD_LIBRARY(libHkTasks.so)
Int_t SETUP() {
	if (!TClass::GetClass("HkTask")) {
		return 1;
	}
	return 0;
}
