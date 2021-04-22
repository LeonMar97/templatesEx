#pragma once
#include "Validator.h"
#include <string>
#include<chrono>
#include<iomanip>

template<typename T>
class NonNegativeValidator : public Validator<T> {
public:
	NonNegativeValidator();
	bool checkValid() override;
private:
};

template <typename T>
NonNegativeValidator<T>::NonNegativeValidator() : Validator<T>(NEG_ERR) {}

template<typename T>
bool NonNegativeValidator<T>::checkValid() {
	auto p = (*this).m_ptrInfoV[0];
	return p >= 0;
}

