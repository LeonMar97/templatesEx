#include "SumValidator.h"
SumValidator::SumValidator(const std::string& errorMsg, Field<int>* total,
	Field<int>* part1, Field<int>* part2)
	:Validator(errorMsg)
{
	m_ptrInfoV.push_back(total);
	m_ptrInfoV.push_back(part1);
	m_ptrInfoV.push_back(part2);
}
//check if two fields 
bool SumValidator::checkValid() {
	
	return (m_ptrInfoV[0] == (m_ptrInfoV[1] + m_ptrInfoV[2]));
	
}


