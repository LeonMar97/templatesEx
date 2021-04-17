#pragma once
#include "Validator.h"
#include <string>
#include<chrono>
#include<iomanip>

template<typename T>
class DateValidator : public Validator<T> {
public:
	
	using Validator<T>::Validator;
	bool checkValid(const T&) override;
	std::string error_msg()override;
private:
	T m_startDate;
	
};

template<typename T>
bool DateValidator<T>::checkValid(const T& value) {
	using clock = std::chrono::system_clock;
	const auto now = clock::to_time_t(clock::now());
	auto calendarTime = std::tm{};
	localtime_s(&calendarTime, &now);
	if (value % 10000 < calendarTime.tm_year + 1900)
		return false;
	
	if (((value % 1000000) / 10000) < calendarTime.tm_mon + 1) 
		return false;
	
	if (((value % 1000000) / 10000) == calendarTime.tm_mon + 1&& 
			(value / 1000000 < calendarTime.tm_mday))
				return false;
		
	return true;

}

template<typename T>
std::string DateValidator<T>:: error_msg() {
	return DATE_ERR;
}
