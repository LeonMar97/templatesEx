#include "RoomValidator.h"
RoomValidator::RoomValidator(const std::string& errorMsg,
	Field<int>* part1, Field<int>* part2, Field<int>* total)
	:Validator(errorMsg)
{
	m_ptrInfoV.push_back(total);
	m_ptrInfoV.push_back(part1);
	m_ptrInfoV.push_back(part2);
}
//check if two fields 
bool RoomValidator::checkValid() {
	
	if (!m_ptrInfoV[2]->getinfo() == (m_ptrInfoV[1]->getinfo() + m_ptrInfoV[0]->getinfo())) {
		for (auto curF : m_ptrInfoV)
			curF->set_valid(false);
		return false;
	}
	return true;
	}
	



