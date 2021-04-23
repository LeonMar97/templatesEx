#include "BaseValidator.h"

BaseValidator::BaseValidator(const std::string& errorMsg)
	: m_errorMsg(errorMsg)
{}
std::string BaseValidator::getErrorMsg() const {
	return m_errorMsg;
}

std::ostream& operator<<(std::ostream& os, BaseValidator& baseValidator) {
	baseValidator.print(os);
	return os;
}