#pragma once
#include<iostream>
#include <string>
template <class T>
class Validator {
public:
	Validator() {};
	virtual bool checkValid(T) = 0;
private :
	std::string m_msg;
};
