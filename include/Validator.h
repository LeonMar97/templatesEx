#pragma once
#include <macros.h>
#include<iostream>
#include <string>
template <class T>
class Validator {
public:
	Validator() {};
	virtual bool checkValid(const T&) = 0;
	virtual std::string error_msg() = 0;
private :
	std::string m_msg = "hello";
};
