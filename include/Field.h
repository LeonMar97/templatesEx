#pragma once
#include <string>
#include "BaseField.h"
#include "Validator.h"

template<typename T>
class Field :public BaseField {

public:
	Field(const std::string& re) :m_request(re){}
	void addValidator(Validator <T>* val);

private:
	T m_info;
	std::string m_request;
	Validator<T>* m_validator;
};

template<typename T>
void Field<T>::addValidator(Validator <T>* val) {
	m_validator = val;
};