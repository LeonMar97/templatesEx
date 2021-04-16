#pragma once
#include "Validator.h"
#include <string>

class NoDigitValidator :public Validator<std::string> {
public:
	NoDigitValidator() {}
	bool checkValid(std::string) override;
};