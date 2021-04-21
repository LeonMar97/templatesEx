#pragma once
#include <vector>
#include <iostream>
#include "FormValidator.h"
#include "Field.h"

class Form {
public:
	Form() {};
	template<typename T>
	void addField(Field<T>* curField);
	template<typename T>
	void addValidator(FormValidator<T>* validator);
	void fillForm();
	bool validateForm();
	friend std::ostream& operator<<(std::ostream& os, const Form& form);
private:
	std::vector<BaseField*>m_validFields ;
	std::vector<BaseField*>m_invalidFields ;
	std::vector<BaseValidator*>m_formValidators;
};

template<typename T>
void Form::addField(Field<T>* curField) {
	m_invalidFields.push_back(curField);
}

template<typename T>
void Form::addValidator(FormValidator<T>* curValidator) {
	m_formValidators.push_back(curValidator);
}
