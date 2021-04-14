#include "Form.h"
//void Form::addField(BaseField* curField) {
	//m_fields.push_back(curField);
//}

void Form::fillForm() {
	for (auto field : m_fields) {
		field->print_request();
		field->fillInfo();
	}
		
}