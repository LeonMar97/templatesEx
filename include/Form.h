#pragma once
#include <vector>
#include <iostream>
#include "Validator.h"
#include "Field.h"

class Form {
public:
	Form() {};
	template<typename T>
	void addField(Field<T>* curField);
	void fillForm();
	bool validateForm();
	friend std::ostream& operator<<(std::ostream& os, const Form& form);
private:
	std::vector<BaseValidator*>m_formValidators;
	std::vector<BaseField*>m_validFields ;
	std::vector<BaseField*>m_invalidFields ;
};

template<typename T>
void Form::addField(Field<T>* curField) {
	m_invalidFields.push_back(curField);
}

