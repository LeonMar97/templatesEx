#pragma once
#include "Validator.h"
#include <string>
#include<chrono>
#include<iomanip>

template<typename T>
class NotGreaterThanValidator : public Validator<T> {
public:
	
	NotGreaterThanValidator(const T& max);
	bool checkValid() override;
private:
	T m_max;
};
template<typename T>
NotGreaterThanValidator<T>::NotGreaterThanValidator(const T& max) : Validator<T>(ROOMS_ERR), m_max(max) {}

template<typename T>
bool NotGreaterThanValidator<T>::checkValid() {
	T* value = this->m_ptrInfoV[0];
	return *value <=m_max;
}
