#include "Form.h"

void Form::fillForm() {
	for (auto field : m_fields) {
		if (!field->is_valid()) {
			field->print_request();
			field->fillContent();
		}
	}
}

bool Form::validateForm() const{
	//checkes first if the normal fields are  validated 
	int counter = 0;
		for (int i = 0; i < m_fields.size(); i++) {
			auto baseField = m_fields[i];
			if (baseField->validContent()) 
				counter++;
		}
	
	//checkes if the fields are validated and only then checks the form
	if (counter==m_fields.size()) {
		counter = 0;
		for (int i = 0; i < m_formValidators.size(); i++) {
			auto baseVal = m_formValidators[i];
			if (baseVal->checkValid()) 
				counter++;
		}
		if (counter==m_formValidators.size())
			return true;
	}
	return false;
}

//operator for printing form with content and error messages
std::ostream& operator<<(std::ostream& os, const Form& form) {
	bool printFormValidatorErrors = true;
	for (auto baseField : form.m_fields) {
		os << std::endl << "---------------------------------------" << std::endl << *baseField << std::endl;
		if (!(baseField->validContent())) {
			os << "Error: " << baseField->getErrorMsg();
			printFormValidatorErrors = false;
		}
		os << std::endl << "---------------------------------------" << std::endl;
	}
	if (printFormValidatorErrors) {
		os << std::endl << "---------------------------------------" << std::endl;
		for (auto baseVal : form.m_formValidators) {
			if (!(baseVal->checkValid()))
				os << std::endl << "Error: " << baseVal->getErrorMsg();
		}
	}
	return os;
}
