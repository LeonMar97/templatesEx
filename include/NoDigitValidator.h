#pragma once
#include "Validator.h"
#include <string>

class NoDigitValidator :public Validator<std::string> {
	//using Validator::Validator;
public:
	NoDigitValidator() {}
};