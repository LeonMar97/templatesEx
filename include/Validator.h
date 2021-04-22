#pragma once
#include <macros.h>
#include<iostream>
#include <string>
#include <vector>
#include"BaseValidator.h"

template <typename T>
class Validator:public BaseValidator {
public:
	Validator(std::string errorMsg) : m_errorMsg(errorMsg) { };
	std::string getMsg();
	void attach( T* ptr);

private:
	std::string m_errorMsg;

protected:
	std::vector< T*>  m_ptrInfoV;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, Validator<T>* validator) {
	os << validator->getMsg();
	return os;
}

template <typename T>
std::string Validator<T>::getMsg() {
	return m_errorMsg;
}

template <typename T>
void Validator<T>::attach( T* ptr) {
	m_ptrInfoV.push_back(ptr);
}
