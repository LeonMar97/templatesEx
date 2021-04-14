#pragma once
#include<iostream>
#include <string>
template <class T>
class Validator {
public:
	Validator() {};
		//bool operator()(T t1);

private :
	std::string m_msg;
};