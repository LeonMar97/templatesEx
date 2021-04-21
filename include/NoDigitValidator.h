#pragma once
#include "FieldValidator.h"
#include <string>

class NoDigitValidator :public FieldValidator<std::string> {
public:
	NoDigitValidator();
	bool checkValid(const std::string&) override;
};

