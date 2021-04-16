#pragma once
#include "Validator.h"
#include <string>

class NoDigitValidator :public Validator<std::string> {
public:
	NoDigitValidator() {}
	bool checkValid(const std::string&) override;
	std::string error_msg()override;

};

