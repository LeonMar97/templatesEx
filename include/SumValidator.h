#pragma once
#include <Validator.h>
class SumValidator : Validator<int>{
 
	SumValidator(const std::string& errorMsg, Field<int>* total, Field<int>* arg1, Field<int>* arg2);
	bool checkValid(const int&) override;
};

template<typename T>
bool SumValidator::checkValid(const int&) {
	return
}
