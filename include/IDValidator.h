#pragma once
#include "Validator.h"
#include <string>

class IDValidator:public Validator<uint32_t> {
public:
	using Validator::Validator;
	bool checkValid(const uint32_t&) override;
	std::string error_msg()override;

};
