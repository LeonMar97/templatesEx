#include "Form.h"

void Form::fillForm() {
	for (auto field : m_invalidFields) {
		if (!field->is_valid()) {
			field->print_request();
			field->fillContent();
		}
	}
}

bool Form::validateForm() const{
	//checkes first if the normal fields are  validated 
	int counter = 0;
		for (int i = 0; i < m_invalidFields.size(); i++) {
			auto baseField = m_invalidFields[i];
			if (baseField->validContent()) 
				counter++;
		}
	
	//checkes if the fields are validated and only then checks the form
	if (counter==m_invalidFields.size()) {
		counter = 0;
		for (int i = 0; i < m_invalidFormValidators.size(); i++) {
			auto baseVal = m_invalidFormValidators[i];
			if (baseVal->checkValid()) 
				counter++;
		}
		if (counter==m_invalidFormValidators.size())
			return true;
	}
	return false;
}

//operator for printing form
std::ostream& operator<<(std::ostream& os, const Form& form) {
	for (auto baseField : form.m_invalidFields) {
		os << std::endl << "---------------------------------------" << std::endl;
		os << *baseField << std::endl;
		if (!(baseField->validContent()))
			os << "Error: " << baseField->getErrorMsg();
		os << std::endl << "---------------------------------------" << std::endl;
	}
	if (!(os.width()) == 0)
		return os;
	os << std::endl << "---------------------------------------" << std::endl;
	for (auto baseVal : form.m_invalidFormValidators) {
		if (!(baseVal->checkValid())) 
			os << std::endl << "Error: " << baseVal->getErrorMsg();
	}
	return os;
}
