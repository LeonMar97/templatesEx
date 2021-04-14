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
private:
	std::vector<BaseField*>m_fields ;
};

template<typename T>
void Form::addField(Field<T>* curField) {
	m_fields.push_back(curField);
}
