#pragma once
#include "Validator.h"
#include <string>

class IDValidator:public Validator<uint32_t> {
public:
	using Validator::Validator;
	bool checkValid(uint32_t) override;
};