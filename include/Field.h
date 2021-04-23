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
	std::string getErrorMsg() const;
	void print_request() const override;
	void print(std::ostream&) const override;
	const T&  getContent() const ;
	const bool  is_valid() const ;
	void set_valid(bool checked);

private:
	T m_content;
	std::string m_request;
	Validator<T>* m_validator;
};

//---------------
template<typename T>
const T &Field<T>:: getContent() const{
	return m_content;
}

//---------------
template<typename T>
std::string Field<T>::getErrorMsg() const {
	return m_validator->getErrorMsg();
}

//---------------
template<typename T>
const bool  Field<T>::is_valid() const{
	return m_validator->isValid();
}

//---------------
template<typename T>
void  Field<T>::set_valid(bool checked) {
	m_validator->setValid(checked);
}

//---------------
template<typename T>
void Field<T>::addValidator(Validator <T>* val) {
	val->attach(&m_content);
	m_validator = val;
};

//---------------
template<typename T>
void Field<T>::print_request() const{
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
void Field<T>::print(std::ostream& os) const {
	os << m_request << " = " << m_content;
}
