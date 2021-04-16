#pragma once
//basic class for pointing at same tamplate field..
class BaseField {
public:
	virtual void print_request() = 0;
	virtual void fillInfo() = 0;
	virtual bool validInfo() = 0;
	template<typename T>
	virtual T getInfo() = 0;
};