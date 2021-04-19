#pragma once
#include "Validator.h"
#include <string>
#include<chrono>
#include<iomanip>

template<typename T>
class NonNegativeValidator : public Validator<T> {
public:
	NonNegativeValidator();
	bool checkValid(const T&) override;
private:
};

template <typename T>
NonNegativeValidator<T>::NonNegativeValidator() : Validator<T>(NEG_ERR) {}

template<typename T>
bool NonNegativeValidator<T>::checkValid(const T& value) {
	return value >= 0;
}

