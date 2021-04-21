#pragma once
#include "BaseFieldValidator.h"

template <typename T>
class FieldValidator : public BaseFieldValidator {
public:
	FieldValidator(const std::string& errorMsg);

};

template <typename T>
FieldValidator<T>::FieldValidator(const std::string& errorMsg)
	: BaseFieldValidator(errorMsg) {}