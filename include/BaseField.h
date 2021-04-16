#include <iostream>  
#pragma once
//basic class for pointing at same tamplate field..
class BaseField {
public:
	virtual void print_request(std::ostream &) = 0;
	virtual void fillInfo() = 0;
	virtual bool validInfo() = 0;
	 std::ostream& operator << (std::ostream &, const BaseField &);

};
