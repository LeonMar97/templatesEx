#include "NoDigitValidator.h"

NoDigitValidator::NoDigitValidator() : Validator(NAME_ERR) {}

//checking if there is a digit in the name
bool NoDigitValidator::checkValid() const {
	return !(m_ptrContentV[0]->find_first_of("0123456789") != std::string::npos);
}
