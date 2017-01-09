R__LOAD_LIBRARY(libHkBase.so)
Int_t SETUP() {
	if (!TClass::GetClass("HkEvent")) {
		return 1;
	}
	return 0;
}
