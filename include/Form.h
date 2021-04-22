#pragma once
#include <vector>
#include <iostream>
#include "Validator.h"
#include "Field.h"

class Form {
public:
	Form() {};
	void fillForm();
	bool validateForm() const;
	friend std::ostream& operator<<(std::ostream& os, const Form& form);

	//templated function for inserting all sorts of fields and validators
	template<typename T>
	void addField(Field<T>* curField);

	template<typename T>
	void addValidator(Validator<T>* curValidator);
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

