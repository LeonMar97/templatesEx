#pragma once
#include <string>
#include "BaseField.h"
#include "Validator.h"

template<typename T>
class Field :public BaseField {

public:
	Field(const std::string& re) :m_request(re), m_validator(NULL){}
	void addValidator(Validator <T>* val);
	void print_request();
	void fillInfo();
	bool validInfo();

private:
	T m_info;
	std::string m_request;
	Validator<T>* m_validator;
};

template<typename T>
void Field<T>::addValidator(Validator <T>* val) {
	m_validator = val;
};

template<typename T>
void Field<T>::print_request() {
	std::cout << m_request;
}

template<typename T>
void Field<T>::fillInfo() {
	std::cin >> m_info;
}

template<typename T>
bool Field<T>::validInfo() {
	return m_validator->checkValid(m_info);
}