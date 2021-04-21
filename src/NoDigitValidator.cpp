#include "NoDigitValidator.h"

NoDigitValidator::NoDigitValidator() : FieldValidator(NAME_ERR) {}

bool NoDigitValidator::checkValid(const std::string& name) {
	return !(name.find_first_of("0123456789") != std::string::npos);
}
