#pragma once
#include <string>
class BaseValidator {
public:
	BaseValidator(const std::string& errorMsg);
	virtual bool checkValid() = 0;
	virtual void print(std::ostream&) = 0;
	std::string getErrorMsg();
private:
	std::string m_errorMsg;
};

std::ostream& operator << (std::ostream& os, BaseValidator&);
