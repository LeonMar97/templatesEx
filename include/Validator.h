#pragma once
#include<iostream>
#include <string>
template <class T>
class Validator {
public:
	Validator() {};
	virtual bool check() = 0;
	virtual bool operator()(const T& t1) {
		check();
	}

private :
	std::string m_msg;
};
