#include <string>
template<class T>
class Field {

public:
	Field(const std::string& re) :m_request(re){};
private:
	T m_info;
	std::string m_request;

};