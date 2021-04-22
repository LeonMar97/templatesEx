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
	template<typename T>
	void addValidator(Validator<T>* curValidator);
	friend std::ostream& operator<<(std::ostream& os, const Form& form);
private:
	std::vector<BaseValidator*>m_invalidFormValidators;
	std::vector<BaseField*>m_invalidFields ;
};

template<typename T>
void Form::addField(Field<T>* curField) {
	m_invalidFields.push_back(curField);
}

template<typename T>

void Form::addValidator(Validator<T> * curValidator) {
	m_invalidFormValidators.push_back(curValidator);
	
}

