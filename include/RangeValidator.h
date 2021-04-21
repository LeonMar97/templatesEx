#pragma once
#include "FieldValidator.h"
#include <string>

template<typename T>
class RangeValidator : public FieldValidator<T> {
public:
	RangeValidator(const T& startRange, const T& endRange);
	bool checkValid(const T&) override;
private:
	T m_startRange;
	T m_endRange;
};

template<typename T>
RangeValidator<T>::RangeValidator(const T& startRange, const T& endRange) : FieldValidator<T>(RANGE_ERR), m_startRange(startRange), m_endRange(endRange) {}

template<typename T>
bool RangeValidator<T>::checkValid(const T& value) {
	return value > m_startRange && value < m_endRange;
}

