#pragma once
#include <iostream>
//basic class for pointing at same tamplate field..
class BaseField {
public:
	virtual void print_request() = 0;
	virtual void fillInfo() = 0;
	virtual bool validInfo() = 0;
	virtual void print(std::ostream&) = 0;
};
std::ostream& operator << (std::ostream& os, BaseField&);
