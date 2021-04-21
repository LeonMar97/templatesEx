#pragma once
#include "BaseValidator.h"
class BaseFormValidator : public BaseValidator{
	 BaseFormValidator(const std::string errorMsg);
	 virtual bool checkValid() = 0;
};