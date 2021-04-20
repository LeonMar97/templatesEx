#pragma once
#include <Validator.h>
#include <macros.h>
class SumValidator : Validator<int>{
 
	SumValidator(const std::string& errorMsg, Field<int>* total, Field<int>* arg1, Field<int>* arg2);
	bool checkValid(const DS&) override;
private:
	DS<Field<int>> addition;


	checkValid(this)
};

template<typename T>
bool SumValidator::checkValid(const int&) {
	return
}
