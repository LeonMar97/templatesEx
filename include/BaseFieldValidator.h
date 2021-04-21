#pragma once
#include "BaseValidator.h"
template<typename  T >
class BaseFieldValidator : public BaseValidator{
public:
	BaseFieldValidator(const std::string &errorMsg );

	 virtual bool checkValid(const T&) = 0;
};
