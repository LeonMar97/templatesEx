#include "BaseValidator.h"

BaseValidator::BaseValidator(const std::string& errorMsg)
	: m_errorMsg(errorMsg)
{}
std::string BaseValidator::getErrorMsg() {
	return m_errorMsg;
}

std::ostream& operator<<(std::ostream& os, BaseValidator& baseField) {
	baseField.print(os);
	return os;
}