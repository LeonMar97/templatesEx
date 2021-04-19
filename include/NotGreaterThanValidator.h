#pragma once
#include "Validator.h"
#include <string>
#include<chrono>
#include<iomanip>

template<typename T>
class NotGreaterThanValidator : public Validator<T> {
public:
	
	NotGreaterThanValidator(const T& max);
	bool checkValid(const T&) override;
private:
	T m_max;
	
};
template<typename T>
NotGreaterThanValidator<T>::NotGreaterThanValidator(const T& max) : Validator<T>(ROOMS_ERR), m_max(max) {}

template<typename T>
bool NotGreaterThanValidator<T>::checkValid(const T& value) {
	return value <=m_max;
}

