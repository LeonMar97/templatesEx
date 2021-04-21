#pragma once
#include "FieldValidator.h"
#include <string>

class IDValidator:public FieldValidator<uint32_t> {
public:
	IDValidator();
	bool checkValid(const uint32_t&) override;
};
