#include<iostream>
#include <string>
#include "BaseValidator.h"
template <class T>
class Validator:public BaseValidator {
	Validator();
		//bool operator()(T t1);

private :
	std::string m_msg;
};