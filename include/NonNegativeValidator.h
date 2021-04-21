#pragma once
#include "FieldValidator.h"
#include <string>
#include<chrono>
#include<iomanip>

template<typename T>
class NonNegativeValidator : public FieldValidator<T> {
public:
	NonNegativeValidator();
	bool checkValid(const T&) override;
private:
};

template <typename T>
NonNegativeValidator<T>::NonNegativeValidator() : FieldValidator<T>(NEG_ERR) {}

template<typename T>
bool NonNegativeValidator<T>::checkValid(const T& value) {
	return value >= 0;
}

