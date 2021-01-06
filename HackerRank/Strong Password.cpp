#include <iostream>
#include <stack>
#include <vector>
#include <string>


enum class CharType {number, lower, upper, special};

bool missingCharType(std::string& inPass, CharType type ) {
	
	std::string numbers = "0123456789";
	std::string lower_case = "abcdefghijklmnopqrstuvwxyz";
	std::string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string special_characters = "!@#$%^&*()-+";

	std::string::iterator i; 
	std::string::iterator j;
	bool isMissing{ true };

	switch (type) {
	case CharType::number :
		for (i = inPass.begin(); i < inPass.end(); i++)
		{
			for (j = numbers.begin(); j < numbers.end(); j++)
			{
				if (*i == *j)
				{
					isMissing = false;
					break;
				}
			}
		}

		break;

	case CharType::lower:
		for (i = inPass.begin(); i < inPass.end(); i++)
		{
			for (j = lower_case.begin(); j < lower_case.end(); j++)
			{
				if (*i == *j) 
				{
					isMissing = false;
					break;
				}
			}
		}
		break;

	case CharType::upper:
		for (i = inPass.begin(); i < inPass.end(); i++)
		{
			for (j = upper_case.begin(); j < upper_case.end(); j++)
			{
				if (*i == *j)
				{
					isMissing = false;
					break;
				}
			}
		}
		break;

	case CharType::special:
		for (i = inPass.begin(); i < inPass.end(); i++)
		{
			for (j = special_characters.begin(); j < special_characters.end(); j++)
			{
				if (*i == *j)
				{
					isMissing = false;
					break;
				}
			}
		}
		break;


	}
	
	return isMissing;
}




int main() {
	int inLength{ 0 }, result{ 0 };
	std::string inPassword;
	

	//take input

	std::cin >> inLength;
	std::cin >> inPassword;

		//check if lowercase present, if no then add char and result++
	if (missingCharType(inPassword, CharType::lower))
	{
		inPassword.append("a");
		result++;
	}

		//check if Uppercase present, if no then add char and result++
	if (missingCharType(inPassword, CharType::upper))
	{
		inPassword.append("A");
		result++;
	}

		//check if special char present, if no then add char and result++
	if (missingCharType(inPassword, CharType::special))
	{
		inPassword.append("#");
		result++;
	}

		//check if number present, if no then add char and result++
	if (missingCharType(inPassword, CharType::number))
	{
		inPassword.append("0");
		result++;
	}

		//check if length is >=6 if no then result += (6 - length) 
	if (inPassword.length() < 6)
	{
		result += (6 - inPassword.length());
	}

	std::cout << result;
}