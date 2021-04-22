#pragma once
#include <string>
class BaseValidator {
public:
	BaseValidator(const std::string& errorMsg);
	virtual bool checkValid() const = 0;
	virtual void print(std::ostream&) const = 0;
	std::string getErrorMsg()const;
private:
	std::string m_errorMsg;
};

std::ostream& operator << (std::ostream& os, BaseValidator&);
