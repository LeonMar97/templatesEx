#include "BaseValidator.h"
std::ostream& operator<<(std::ostream& os, BaseValidator* validator) {
	os << validator->getMsg();
	return os;
}

std::string BaseValidator::getMsg() {
	return m_errorMsg;
}