#pragma once
#include <string>

namespace nc {


	std::string toUpper(std::string str);
	std::string toLower(std::string str);
	bool IsEqualIgnoreCase(std::string str1, std::string str2);
	std::string CreateUnique(std::string str);

}