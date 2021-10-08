#pragma once
#include "Source1.cpp"
#include <string>
#include <iostream>
class boss
{
public:
	std::string name;
	int health;
	int drop;
	boss(const std::string& a, const int b, const int c) { };
	void text()
	{
		std::cout << "BOSS SUMMONED" << std::endl;
	}
private:

};

class pet2
{
public:
	pet2(const std::string& a) {};
	std::string name;
	void pikachu(int& weapon)
	{
		weapon++;
		system("cls");
	}
private:
};