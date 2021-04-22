#pragma once
#include "Field.h"
class SumValidator :Validator<Field<int>>{
public:
	SumValidator(const std::string& errorMsg,Field<int>*total, Field<int>*part1, Field<int>*part2);
	bool checkValid()override;

};

