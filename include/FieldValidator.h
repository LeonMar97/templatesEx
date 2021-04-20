#pragma once
#include <BaseFieldValidator.h>

template <typename T>
class FieldValidator : public BaseFieldValidator {
	FieldValidator(const std::string& errorMsg);
};

template <typename T>
FieldValidator::FieldValidator(const std::string& errorMsg)
	: BaseFieldValidator(errorMsg) 
{}