#pragma once
#include "Validator.h"
#include <string>

template<typename T>
class RangeValidator : public Validator<T> {
public:
	RangeValidator(const T& startRange, const T& endRange);
	bool checkValid() const override;
private:
	T m_startRange;
	T m_endRange;
};

template<typename T>
RangeValidator<T>::RangeValidator(const T& startRange, const T& endRange) 
	: Validator<T>(RANGE_ERR), m_startRange(startRange), m_endRange(endRange) 
{}

template<typename T>
bool RangeValidator<T>::checkValid() const{
	auto value = this->m_ptrContentV[0]; //get the first (and only one in this case) value from the vector
	return *value > m_startRange && *value < m_endRange;
}
