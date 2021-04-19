#pragma once
#include "Validator.h"
#include <string>

class IDValidator:public Validator<uint32_t> {
public:
	IDValidator();
	bool checkValid(const uint32_t&) override;
};
