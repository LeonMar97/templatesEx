#include "Form.h"
//void Form::addField(BaseField* curField) {
	//m_fields.push_back(curField);
//}

void Form::fillForm() {
	for (auto field : m_invalidFields) {
		field->print_request();
		field->fillInfo();
	}
		
}
bool Form::validateForm() {
	for (int i = 0; i < m_invalidFields.size(); i++) {
		auto field = m_invalidFields[i];
		if (field->valid_info()) {
			m_validFields.push_back(field);
			m_invalidFields.erase(m_invalidFields.begin() + i);
		}
		return m_invalidFields.empty();
	}
}