#pragma once
#include <string>
#include "BaseField.h"
#include "Validator.h"

template<typename T>
class Field :public BaseField {

public:
	Field(const std::string& re) :m_request(re) {}
	void addValidator(Validator <T>* val);
	void fillInfo();
	bool validInfo();
	void print_request()override;
	void print(std::ostream&) override;
	const T&  getinfo();
private:
	T m_info;
	std::string m_request;
	Validator<T>* m_validator;
};
template<typename T>
const T &Field<T>:: getinfo() {
	return m_info;
}

template<typename T>
void Field<T>::addValidator(Validator <T>* val) {
	val->attach(&m_info);
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
	return m_validator->checkValid();
}
template<typename T>
void Field<T>::print(std::ostream& os) {
	os << std::endl;
	os << "---------------------------------------" << std::endl;
	os << "---------------------------------------" << std::endl;

	os << m_request << " = " << m_info << '\t' << m_validator << std::endl;
}
