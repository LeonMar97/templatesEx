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
	
	if (!(m_ptrInfoV[0]->getContent() == (m_ptrInfoV[1]->getContent() + m_ptrInfoV[2]->getContent()))) {
		for (auto curF : m_ptrInfoV)
			curF->set_valid(false);
		return false;
	}
	return true;//if the argument is true the fields ae by refrence and already truw
	
}


