#include <vector>
#include <iostream>
#include "Validator.h"
#include "Field.h"

class Form {
public:
	Form() {};
	void addField(BaseField* curField);
private:
	std::vector<BaseField*>m_fields ;
};