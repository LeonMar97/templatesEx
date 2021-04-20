#pragma once
class BaseFieldValidator : public BaseValidator{
	BaseFieldValidator(std::string errorMsg);
	template<typename T>
	bool checkValid(const T&) = 0;
};