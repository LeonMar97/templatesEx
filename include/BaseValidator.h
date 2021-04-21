#pragma once
#include <macros.h>
#include<iostream>
#include <string>

class BaseValidator {
public:
	BaseValidator(std::string errorMsg) : m_errorMsg(errorMsg) {}
	std::string getMsg();
private:
	std::string m_errorMsg;
};
