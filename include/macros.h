#include <string>
const std::string NAME_ERR = "can't contain digits";
const std::string ID_ERR = "Wrong control digit";
const std::string RANGE_ERR = "out of range";
const std::string DATE_ERR = "date has already passed";
const std::string NEG_ERR = "cant be negative";
const std::string NUM_PEOPLE_ERR = "Number of adults and children doesn't match total number of people";
const std::string ROOMS_ERR = "the maximum is 10 rooms";
const std::string BED_ERR = "Number of people doesn't match to the maximum number of people that can be entered as you invite";

const int MAX_ROOMS = 10;

template <typename T>
struct DS {
	T arg1;
	T arg2;
	T sum;
};