#pragma once
#include <string>
#include "BaseField.h"
#include "Validator.h"

template<typename T>
class Field :public BaseField {

public:
	Field(const std::string& re) :m_request(re), m_validator(NULL){}
	void addValidator(Validator <T>* val);
	 std::ostream& operator << (std::ostream&,const  BaseField &)override;
	void fillInfo();
	
	bool validInfo();
	virtual void print_request() ;
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
std::ostream& operator << (std::ostream& os,const  BaseField&b ) {
	Field<T> cur = (static_cast<Field<T>>(b));
	return os<<cur.m_request<< " = " <<cur.m_info;
}


template<typename T>
void Field<T>::fillInfo() {
	std::cin >> m_info;
}

template<typename T>
bool Field<T>::validInfo() {
	return m_validator->checkValid(m_info);
}




