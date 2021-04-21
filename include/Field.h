#pragma once
#include <string>
#include "BaseField.h"
#include "FieldValidator.h"

template<typename T>
class Field :public BaseField {

public:
	Field(const std::string& re) :m_request(re), m_validators(NULL){}
	void addValidator(FieldValidator <T>* val);
	void fillInfo();
	bool validInfo();
	void print_request()override ;
	void print(std::ostream&) override;
private:
	//T m_error;
	T m_info;
	std::string m_request;
	std::vector<FieldValidator<T>*> m_validators;
};

template<typename T>
void Field<T>::addValidator(FieldValidator <T>* val) {
	m_validators.push_back(val);
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
	for (BaseFieldValidator cur* : m_validators) {
		if (!cur->checkValid(m_info))
			return false;
	}
	return true;
}
template<typename T>
void Field<T>::print(std::ostream& os) {
	os << std::endl;
	os << "---------------------------------------" << std::endl;
	os << "---------------------------------------" << std::endl;

	os << m_request << " = " << m_info<<'\t' << m_validators <<std::endl;
}
