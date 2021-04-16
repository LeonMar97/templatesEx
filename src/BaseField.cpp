#include "BaseField.h"

std::ostream& operator<<(std::ostream& os, BaseField& baseField) {
	baseField.print(os);
	return os;
}


