#pragma once
#include "Field.h"
class RoomValidator :public Validator<Field<int>>{
public:
	RoomValidator(const std::string& errorMsg, Field<int>*part1, Field<int>*part2, Field<int>* total);
	bool checkValid()override;
};

