#pragma once
#include <macros.h>
#include<iostream>
#include <string>
template <class T>
class Validator {
public:
	Validator(std::string errorMsg) : m_errorMsg(errorMsg) {};
	virtual bool checkValid(const T&) = 0;
	std::string getMsg();
private :
	std::string m_errorMsg;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, Validator<T> *validator){
	os << validator->getMsg();
	return os;
}

template <typename T>
std::string Validator<T>::getMsg() {
	return m_errorMsg;
}
