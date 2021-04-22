#pragma once
#include <macros.h>
#include<iostream>
#include <string>
#include <vector>
#include"BaseValidator.h"

//template validator class

template <typename T>
class Validator:public BaseValidator {
public:
	Validator(std::string errorMsg) : BaseValidator(errorMsg) { };
	void print(std::ostream&) const override;
	void attach( T* ptr); //attach the necessary information to evaluate to this instantiation

private:
protected:
	std::vector< T*>  m_ptrInfoV; //The entire data this instantiation needs to evaluate
};

template<typename T>
std::ostream& operator<<(std::ostream& os, Validator<T>* validator) {
	os << validator->getMsg();
	return os;
}

//put int the vector the necessary information to evaluate
template <typename T>
void Validator<T>::attach( T* ptr) {
	m_ptrInfoV.push_back(ptr);
}

template<typename T>
void Validator<T>::print(std::ostream& os) const {
	for (auto field : m_ptrInfoV) {
		os << *field << std::endl; //print the request + the information user has inserted
	}
}
