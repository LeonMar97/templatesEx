#pragma once
#include <iostream>
//basic class for pointing at same tamplate field..
class BaseField {
public:
	virtual void print_request() = 0;
	virtual std::string getErrorMsg() = 0;
	virtual void fillContent() = 0;
	virtual bool validContent() = 0;
	virtual void print(std::ostream&) = 0;
	virtual const bool  is_valid()=0;
};
std::ostream& operator << (std::ostream& os, BaseField&);
