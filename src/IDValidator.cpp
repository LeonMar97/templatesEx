#pragma once
#include "IDValidator.h"
//took the java script code from wiki and changed to cpp..

IDValidator::IDValidator()
    : Validator(ID_ERR)
{}

bool IDValidator::checkValid() const{
    auto curId = *m_ptrContentV[0];
    auto id = std::to_string(curId);
    int sum = 0, incNum;
    if(id.length() != 9 ) {  // Make sure ID is formatted properly
        return false;
    }
    for (int i = 0; i < id.length();i++) {
		incNum = int(id[i]-'0') * ((i % 2) + 1);  // Multiply number by 1 or 2
		sum += (incNum > 9) ? incNum - 9 : incNum;  // Sum the digits up and add to total
	}
	return (!(sum % 10));
}