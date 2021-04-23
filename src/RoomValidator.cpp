#include "RoomValidator.h"
RoomValidator::RoomValidator(const std::string& errorMsg,
	Field<int>* pairRoom, Field<int>* familyRoom, Field<int>* totalPeople)
	:Validator(errorMsg)
{
	m_ptrContentV.push_back(pairRoom);
	m_ptrContentV.push_back(familyRoom);
	m_ptrContentV.push_back(totalPeople);
}
//check if two 
bool RoomValidator::checkValid() const{
	//check of total people is 3*pairRoom + 5*familyRoom
	if (!(m_ptrContentV[2]->getContent() <= (2*m_ptrContentV[0]->getContent() + 5*m_ptrContentV[1]->getContent()))) {
		//if not correct - user needs to resend the information, set validation state of all fields to false
		for (auto curF : m_ptrContentV)
			curF->set_valid(false);
		return false; //the number of rooms does not match the number of people 
	}
	return true; //the number of rooms matches the number of people
}
