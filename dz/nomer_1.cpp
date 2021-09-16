#include<iostream>
#include <vector>
int main()
{
	std::string s1 = "OMG, RABOTAET!\nYRA ETO\nBOMBA !#*&@)#@(";
	std::vector <char> store = {' ','\n'};
	std::vector <std::string> sklad = {};
	int first = 0;
	int last = 0;
	int num = 0;
	while (s1.size()!=0)
	{
		int p = s1.find(store[1]);
		int q = s1.find(store[0]);
		if (p == -1 && q != -1)
		{
			last = q;
		}
		else if (q == -1 && p != -1)
		{
			last = p;
		}
		else if (p == -1 && q == -1)
		{
			last = s1.size();
		}
		else 
		{
			last = std::min(p, q);
		}

		std::string d= s1.substr(0, last);
		sklad.push_back(d);
		s1.erase(0, last+1);
	}
	for (int i = 0; i < sklad.size(); i++) std::cout << "\n" << sklad[i] << "\n";
	return 0;
}