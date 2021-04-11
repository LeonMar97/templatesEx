#include <iomanip>
#include <Function_list.h>
#pragma once
int main() {

	std::cout << std::fixed << std::setprecision(2) <<std::noshowpoint;
	auto l = Function_list();
	l.run();
	
	
	return true;
}
