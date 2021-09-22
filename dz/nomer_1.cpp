#include<iostream>
#include <vector>
int main()
{
	std::string s1 = "OMG, RABOTAET!\nYRA ETO\nBOMBA !#*&@)#@(";
	std::vector <char> store = { ' ','\n' };
	std::vector <std::string> sklad = {};
	int kolwo = std::size(s1);
	int first = 0;
	for (int i =0;i<kolwo;i++)
	{
		if (ispunct(s1[i]) || isspace(s1[i])||i==kolwo-1)
		{
			if (i > first)
			{
				std::string d = s1.substr(first, i-first);
				sklad.push_back(d);

			}
			first = i + 1;
		}
	}
	for (int i = 0; i < sklad.size(); i++) std::cout << "\n" << sklad[i] << "\n";
	return 0;
}
