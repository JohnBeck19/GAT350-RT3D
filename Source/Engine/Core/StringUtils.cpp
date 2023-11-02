#include "StringUtils.h"
namespace nc {
	std::string nc::toUpper(std::string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = str[i] - 32;
			}
		}
		return str;
	}

	std::string nc::toLower(std::string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] = str[i] + 32;
			}
		}
		return str;
	}

	bool nc::IsEqualIgnoreCase(std::string str1, std::string str2)
	{
		return (toLower(str1) == toLower(str2));
	}

	std::string CreateUnique(const std::string& str)
	{
		static uint32_t unique = 0;

		return str + std::to_string(unique++);
	}




}
