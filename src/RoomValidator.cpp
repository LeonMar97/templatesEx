#include "RoomValidator.h"
RoomValidator::RoomValidator(const std::string& errorMsg,
	Field<int>* pairRoom, Field<int>* familyRoom, Field<int>* totalPeople)
	:Validator(errorMsg)
{
	m_ptrInfoV.push_back(pairRoom);
	m_ptrInfoV.push_back(familyRoom);
	m_ptrInfoV.push_back(totalPeople);
}
//check if two fields 
bool RoomValidator::checkValid() {
	if (!(m_ptrInfoV[2]->getContent() == (2*m_ptrInfoV[0]->getContent() + 5*m_ptrInfoV[0]->getContent()))) {
		for (auto curF : m_ptrInfoV)
			curF->set_valid(false);
		return false;
	}
	return true;
}


