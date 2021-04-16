#include "NoDigitValidator.h"

bool NoDigitValidator::checkValid(const std::string& name) {
	return !(name.find_first_of("0123456789") != std::string::npos);
}

std::string NoDigitValidator::error_msg() {
	return NAME_ERR;
}