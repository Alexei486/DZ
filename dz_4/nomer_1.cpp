#include <iostream>
#include <string>
#include<cmath>
#include <stdlib.h> 
#include <time.h>
#include <dos.h>
#include <windows.h>
struct Boss
{
	std::string name1;
	int Health;
	int drop;
};



void Fight(int Weapon, int Pet,int Money)
{
	int Health = rand() % 50;
	int move = 5;
	int Drop = Health / 10;
	while (move != 0)
	{
		std::cout << "Health: " << Health << "\n";
		std::cout << "summary: " << Weapon + Pet << "\n";

		std::cout << "you have " + std::to_string(move) + " moves left" << "\n";
		Health = Health - Weapon - Pet ;
		--move;
	}
	if (Health > 0)
	{
		std::cout << "You lose";
		Sleep(3000);
		system("cls");
	}
	else
	{
		std::cout << "You got: " << Drop <<"Money"<< "\n";
		Money += Drop;
		Sleep(3000);
		system("cls");
	}
}


void To_Spam(double Money,int Weapon,int Pet)
{
	std::cout << "Money: " << Money << "\n";
	std::cout << "Weapon attack: " << Weapon <<"\n";
	std::cout << "Pet attack: " << Pet << "\n";
	std::cout << "What would you like? " << "\n";
	std::cout << "press ENTER to farm some money " << "\n";
	std::cout << "to enter the store write: Shop " << "\n";
	std::cout << "to enter the boss fight write: Boss " << "\n";
	std::cout << "to enter the boss fight write: Fight " << "\n";
	std::cout << "________________________________________" << "\n";




	
	return;
}

void Shop(double *Money,int *Weapon,int *Upgrade1, int *Upgrade2, double *Cost,int *Pet)
{
	std::string Text_Shop;
	std::cout << "Money: " << *Money << "\n";
	std::cout << "Weapon attack: " << *Weapon << "\n";
	std::cout << "Pet attack: " << *Pet << "\n";
	std::cout << "improve weapon(+1 attack) cost: " << pow(1.5 , *Upgrade1) * *Cost << "\n";
	std::cout << "improve pet(+1 attack) cost: " << pow(2,*Upgrade2) * *Cost << "\n";
	std::cout << "To purchase enter: Buy weapon " "\n";
	std::cout << "To purchase enter: Buy pet " "\n";
	std::cout << "To exit the store, enter: Back " "\n";
	std::cout << "________________________________________" << "\n";
	std::getline(std::cin, Text_Shop);
	if (Text_Shop == "Buy pet")
	{
		if (*Money > pow(1.5, *Upgrade2) * *Cost)
		{
			*Money -= pow(1.5,* Upgrade2) * *Cost;
			*Pet += 1;
			*Upgrade2 += 1;
			system("cls");
			std::cout <<"\n" << "\n"<< "Thank you for your purchase" ;
			Sleep(1000);
			system("cls");
			Shop(Money, Weapon, Upgrade1, Upgrade2, Cost, Pet);
		}
		else
		{
			system("cls");
			std::cout << "\n" << "\n" << "Not enough money";
			Sleep(1000);
			system("cls");
			Shop(Money, Weapon, Upgrade1, Upgrade2, Cost, Pet);
		}
	}
	if (Text_Shop == "Buy weapon")
	{
		if (*Money > pow(1.5, *Upgrade1) * *Cost)
		{
			*Money -= pow(1.5, *Upgrade1) * *Cost;
			*Weapon += 1;
			*Upgrade1 += 1;
			system("cls");
			std::cout << "\n" << "\n" << "Thank you for your purchase";
			Sleep(1000);
			system("cls");
			Shop(Money, Weapon, Upgrade1, Upgrade2, Cost, Pet);
		}
		else
		{
			system("cls");
			std::cout << "\n" << "\n" << "Not enough money";
			Sleep(1000);
			system("cls");
			Shop(Money, Weapon, Upgrade1, Upgrade2, Cost, Pet);
		}
	}
	if (Text_Shop == "Back")
	{
		system("cls");
	return ;
	}
	return ;
}
void Start_Game(double *Money, int *Weapon, int *Pet, double *Cost, int *Upgrade1, int *Upgrade2,struct Boss Tom,struct  Boss Marya )
{
	int n = 1;
	std::string m;
	while (n > -10)
	{
		To_Spam(*Money,*Weapon, *Pet);
		std::getline(std::cin, m);
		system("cls");
		if (m == "Shop")
		{
			Shop(Money, Weapon, Upgrade1, Upgrade2,Cost, Pet);
		}
		if (m == "Fight")
		{
			Fight(*Weapon,*Pet,*Money);
		}
		if (m == "Boss")
		{
			std::cout << "your attack in the boss fight: "<< 10* *Weapon <<"\n";
			Sleep(3000);
			std::cout << "Boss name : " << Tom.name1 << "\n" << "Boss health: "<< Tom.Health << "\n" << "Drop from the boss: " << Tom.drop << "\n";
			Sleep(3000);
			if (Tom.Health < 10 * *Weapon)
			{
				system("cls");
				std::cout << "Fine. But that is not all";
				Sleep(3000);
				system("cls");
				std::cout << "Boss name : " << Marya.name1 << "\n" << "Boss health: " << Marya.Health << "\n" << "Drop from the boss: " << Marya.drop << "\n";
				Sleep(3000);
				if (Marya.Health < 10 * *Weapon)
				{
					
					system("cls");
					std::cout << "YOU WON!!!";
					Sleep(5000);
				}
				else
				{
					system("cls");
					std::cout << "YOU LOSE!";
					Sleep(5000);
				}
			}
			else
			{

				system("cls");
				std::cout << "YOU LOSE!";
				Sleep(5000);
			}

		}
		else
		{
			*Money += *Weapon;
		}
	}
	Start_Game (Money, Weapon, Pet, Cost, Upgrade1, Upgrade2, (Boss(Tom)), (Boss(Marya)));
	return;
}

int main()
{
	Boss Tom;
	Tom.name1 = "Tommy_gungsta";
	Tom.Health = 100;
	Tom.drop = 1000;

	Boss Marya;
	Marya.name1 = "knife";
	Marya.Health = 125;
	Marya.drop = 2000;

		int Pet = 0;
		double Cost = 100;
		int Upgrade1 = 1;
		int Upgrade2 = 1;
		int Weapon = 15;
		double Money = 0;
	Start_Game(  &Money, &Weapon, &Pet, &Cost, &Upgrade1, &Upgrade2,( Boss (Tom)), (Boss(Marya)));
	return 0;
}