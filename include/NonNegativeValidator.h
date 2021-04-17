#pragma once
#include "Validator.h"
#include <string>
#include<chrono>
#include<iomanip>

template<typename T>
class NonNegativeValidator : public Validator<T> {
public:
	
	using Validator<T>::Validator;
	bool checkValid(const T&) override;
	std::string error_msg()override;
private:
	
	
};

template<typename T>
bool NonNegativeValidator<T>::checkValid(const T& value) {
	return value >= 0;
}

template<typename T>
std::string NonNegativeValidator<T>:: error_msg() {
	return NIGHTS_ERR;
}
