#include "NoDigitValidator.h"

bool NoDigitValidator::checkValid(const std::string& name) {
	return !(name.find_first_of("0123456789") != std::string::npos);
}