#pragma once
#include "Validator.h"
#include <string>
#include<chrono>
#include<iomanip>

template<typename T>
class NotGreaterThanValidator : public Validator<T> {
public:
	
	NotGreaterThanValidator(const T& max);
	bool checkValid() const override;
private:
	T m_max;
};
template<typename T>
NotGreaterThanValidator<T>::NotGreaterThanValidator(const T& max) : Validator<T>(ROOMS_ERR), m_max(max) {}

template<typename T>
bool NotGreaterThanValidator<T>::checkValid() const{
	auto value = this->m_ptrContentV[0];
	return *value <=m_max;
}
