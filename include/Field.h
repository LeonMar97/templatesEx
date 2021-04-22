#pragma once
#include <string>
#include "BaseField.h"
#include "Validator.h"

template<typename T>
class Field :public BaseField {

public:
	Field(const std::string& re) :m_request(re) {}
	void addValidator(Validator <T>* val);
	void fillContent();
	bool validContent();
	virtual std::string getErrorMsg();
	void print_request()override;
	void print(std::ostream&) override;
	const T&  getContent();
	const bool  is_valid();
	void set_valid(bool checked);

private:
	T m_content;
	std::string m_request;
	Validator<T>* m_validator;
	bool m_valid=false;
};

//---------------
template<typename T>
const T &Field<T>:: getContent() {
	return m_content;
}

//---------------
template<typename T>
std::string Field<T>::getErrorMsg() {
	return m_validator->getErrorMsg();
}

//---------------
template<typename T>
const bool  Field<T>::is_valid() {
	return m_valid;
}

//---------------
template<typename T>
void  Field<T>::set_valid(bool checked) {
	m_valid = checked;
}

//---------------
template<typename T>
void Field<T>::addValidator(Validator <T>* val) {
	val->attach(&m_content);
	m_validator = val;
};

//---------------
template<typename T>
void Field<T>::print_request() {
	std::cout << m_request;
}

//---------------
template<typename T>
void Field<T>::fillContent() {
	std::cin >> m_content;
}

//---------------
template<typename T>
bool Field<T>::validContent() {
	bool validation = m_validator->checkValid();
	set_valid(validation);
	return validation;
}

//---------------
template<typename T>
void Field<T>::print(std::ostream& os) {
	os << m_request << " = " << m_content;
}
