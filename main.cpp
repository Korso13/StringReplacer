#include <iostream>
#include <map>
#include <string>

char MakeLowerCase(const char& const InChar)
{
	char OutCh;
	if (InChar <= -33 && InChar >= -64)
	{
		OutCh = InChar + 32;
	}
	else if (InChar == -88)
	{
		OutCh = -72;
	}
	else
	{
		OutCh = static_cast<char>(tolower(InChar));
	}
	return OutCh;
}


int main()
{
	system("chcp 1251");

	std::cout << "Enter text string:" << std::endl;
	std::string InString;
	getline(std::cin, InString);
	
	std::map<char, int> Dublicates;
	
	for (int i = 0; i < InString.size(); i++)
	{
		auto InsertResult = Dublicates.insert({MakeLowerCase(InString[i]), i});
		if (InsertResult.second == true)
		{
			InString.replace(i, 1, 1, '(');
		}
		else
		{
			InString.replace(i, 1, 1, ')');
			if (InString[InsertResult.first->second] != ')')
				InString.replace(InsertResult.first->second, 1, 1, ')');
		}
	}

	std::cout << "Converted string: " << InString << std::endl;
	std::cin.get();
	return 0;
}