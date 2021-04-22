#pragma once
#include "Validator.h"
#include <string>
#include<chrono>
#include<iomanip>

template<typename T>
class DateValidator : public Validator<T> {
public:
	DateValidator();
	bool checkValid() override;
private:
};

template <typename T>
DateValidator<T>::DateValidator() 
	: Validator<T>(DATE_ERR)
{}

template<typename T>
bool DateValidator<T>::checkValid() {
	T value = *(this->m_ptrInfoV[0]);
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

    if (value / 1000000 < calendarTime.tm_mday)//if we on the same year and month 
        return false;
    return true;
}
