#include "Form.h"

//void Form::addField(BaseField* curField) {
	//m_fields.push_back(curField);
//}

void Form::fillForm() {
	
	for (auto field  : m_invalidFields) {
		
		field->print_request();
		field->fillInfo();
	}
}

bool Form::validateForm() {
	for (int i = 0; i < m_invalidFields.size(); i++) {
		auto baseField = m_invalidFields[i];
		if (baseField->validInfo()) {
			m_validFields.push_back(baseField);
			m_invalidFields.erase(m_invalidFields.begin() + i);
		}
	}
	return m_invalidFields.empty();
}

//operator for printing field
std::ostream& operator<<(std::ostream& os, const Form& form) {
	for (auto baseField : form.m_invalidFields) {
		os << *baseField;
	}
	return os;
}
