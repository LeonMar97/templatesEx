#pragma once
#include <macros.h>
#include<iostream>
#include <string>
#include <vector>

template <typename T>
class Validator {
public:
	Validator(std::string errorMsg) : m_errorMsg(errorMsg) { };
	virtual bool checkValid() = 0;
	std::string getMsg();
	void attach(const T* ptr);
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
void Validator<T>::attach(const T* ptr) {
	m_ptrInfoV.push_back(ptr);
}
