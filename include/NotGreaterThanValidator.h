#pragma once
#include "Validator.h"
#include <string>
#include<chrono>
#include<iomanip>

template<typename T>
class NotGreaterThanValidator : public Validator<T> {
public:
	
	using Validator<T>::Validator;
	NotGreaterThanValidator(const T& max);

	bool checkValid(const T&) override;
	std::string error_msg()override;
private:
	T m_max;
	
};
template<typename T>
NotGreaterThanValidator<T>::NotGreaterThanValidator(const T& max) :m_max(max) {}

template<typename T>
bool NotGreaterThanValidator<T>::checkValid(const T& value) {
	return value <=m_max;
}

template<typename T>
std::string NotGreaterThanValidator<T>:: error_msg() {
	return ROOMS_ERR;
}
