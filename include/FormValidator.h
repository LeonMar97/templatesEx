#pragma once
#include "BaseFormValidator.h"
#include "Field.h"
template<typename T>
class FormValidator:public BaseFormValidator
{
public:
	FormValidator::FormValidator(const std::string& error, Field<T>* arg1,
		Field<T>* arg2, Field<T>* arg3);
	bool checkValid();
private:
	Field<T>* arg1,*arg2,*arg;
	
};
template<typename T>
FormValidator<T>::FormValidator(const std::string& error, Field<T>* arg1,
	Field<T>* arg2, Field<T>* arg3)
	:BaseFormValidator(error),arg1(arg1),arg2(arg2),arg3(arg3)
{

}
