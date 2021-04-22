#pragma once
#include <macros.h>
#include<iostream>
#include <string>
#include <vector>
#include"BaseValidator.h"

template <typename T>
class Validator:public BaseValidator {
public:
	Validator(std::string errorMsg) : BaseValidator(errorMsg) { };
	void print(std::ostream&) override;
	void attach( T* ptr);

private:
protected:
	std::vector< T*>  m_ptrInfoV;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, Validator<T>* validator) {
	os << validator->getMsg();
	return os;
}

template <typename T>
void Validator<T>::attach( T* ptr) {
	m_ptrInfoV.push_back(ptr);
}

template<typename T>
void Validator<T>::print(std::ostream& os) {
	for (auto field : m_ptrInfoV) {
		os << *field << std::endl;
	}
}
