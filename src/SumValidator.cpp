#include "SumValidator.h"
SumValidator::SumValidator(const std::string& errorMsg, Field<int>* total,
	Field<int>* part1, Field<int>* part2)
	:Validator(errorMsg)
{
	m_ptrContentV.push_back(total);
	m_ptrContentV.push_back(part1);
	m_ptrContentV.push_back(part2);
}
//check if two fields 
bool SumValidator::checkValid() const {
	
	//check if the sum is alright
	if (!(m_ptrContentV[0]->getContent() == (m_ptrContentV[1]->getContent() + m_ptrContentV[2]->getContent()))) {
		for (auto curF : m_ptrContentV) //if not, user needs to resend information - set validation state of all fields to false
			curF->set_valid(false);
		return false;
	}
	return true;//if the argument is true the fields ae by refrence and already true
	
}


