#pragma once
#include "FieldValidator.h"
#include <string>
#include<chrono>
#include<iomanip>

template<typename T>
class DateValidator : public FieldValidator<T> {
public:
	DateValidator();
	bool checkValid(const T&) override;
private:
};

template <typename T>
DateValidator<T>::DateValidator() 
	: FieldValidator<T>(DATE_ERR)
{}

template<typename T>
bool DateValidator<T>::checkValid(const T& value) {
    using clock = std::chrono::system_clock;
    const auto now = clock::to_time_t(clock::now());
    auto calendarTime = std::tm{};
    localtime_s(&calendarTime, &now);
    if (value % 10000 > calendarTime.tm_year + 1900)
        return true;
    if (value % 10000 < calendarTime.tm_year + 1900)
        return false;

    if (((value % 1000000) / 10000) < calendarTime.tm_mon + 1)
        return false;
    if (((value % 1000000) / 10000) > calendarTime.tm_mon + 1)
        return true;

    if (value / 1000000 < calendarTime.tm_mday) 
        return false;

    return true;

      

}
