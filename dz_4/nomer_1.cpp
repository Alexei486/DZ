#include <iostream>
#include <string>
#include<cmath>
#include <stdlib.h> 
#include <time.h>
#include<random>
#include<thread>
struct boss
{
	std::string name;
	int health;
	int drop;
};



void fight(int weapon, int pet, int money)
{
	std::mt19937 gen;
	gen.seed(time(0));
	std::uniform_int_distribution<> uid(0, 100);
	int health = uid(gen);
	auto move = 5;
	auto drop = health / 10;
	auto debuff = 0;
	std::string m;
	while (move != 0)
	{
		std::cout << "press ENTER to fight " << "\n";
		std::getline(std::cin, m);
		system("cls");
		if (m == "Cheat")
		{
		money = 0;
		std::cout << "Go away, Hacker!" << "\n";
		}
		else
		{
			if (health > 0)
			{
				debuff += gen() % 2;
				std::cout << "Mob gave you debuff: " << debuff << "\n";
				std::cout << "Mob Health: " << health << "\n";
				std::cout << "summary attack: " << weapon + pet - debuff<< "\n";
				std::cout << "you have " + std::to_string(move) + " moves left" << "\n";
				health = health - weapon - pet;
				--move;
			}
			else
			{
				std::cout << "Mob Health: " << "0" << "\n";
				std::cout << "You won! ";
				break;
			}

		}

	}
	if (health > 0)
	{
		std::cout << "You lose" << "\n";
		std::this_thread::sleep_for(std::chrono::seconds(3));
		system("cls");
	}
	else
	{
		std::cout << "You got: " << "\n" <<drop << "Money" << "\n";
		money += drop;
		std::this_thread::sleep_for(std::chrono::seconds(3));
		system("cls");
	}
}


void to_spam(double money, int weapon, int pet)
{
	std::cout << "Money: " << money << "\n";
	std::cout << "Weapon attack: " << weapon << "\n";
	std::cout << "Pet attack: " << pet << "\n";
	std::cout << "What would you like? " << "\n";
	std::cout << "press ENTER to farm some money " << "\n";
	std::cout << "to enter the store write: Shop " << "\n";
	std::cout << "to enter the boss fight write: Boss " << "\n";
	std::cout << "to enter the boss fight write: Fight " << "\n";
	std::cout << "________________________________________" << "\n";





	return;
}

void Shop(double* money, int* weapon, int* upgrade1, int* upgrade2, double* cost, int* pet)
{
	std::string Text_Shop;
	std::cout << "Money: " << *money << "\n";
	std::cout << "Weapon attack: " << *weapon << "\n";
	std::cout << "Pet attack: " << *pet << "\n";
	std::cout << "improve weapon(+1 attack) cost: " << pow(1.5, *upgrade1) * *cost << "\n";
	std::cout << "improve pet(+1 attack) cost: " << pow(2, *upgrade2) * *cost << "\n";
	std::cout << "To purchase enter: Buy weapon " "\n";
	std::cout << "To purchase enter: Buy pet " "\n";
	std::cout << "To exit the store, enter: Back " "\n";
	std::cout << "________________________________________" << "\n";
	std::getline(std::cin, Text_Shop);
	if (Text_Shop == "Buy pet")
	{
		if (*money > pow(1.5, *upgrade2) * *cost)
		{
			*money -= pow(1.5, *upgrade2) * *cost;
			*pet += 1;
			*upgrade2 += 1;
			system("cls");
			std::cout << "\n" << "\n" << "Thank you for your purchase";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			system("cls");
			Shop(money, weapon, upgrade1, upgrade2, cost, pet);
		}
		else
		{
			system("cls");
			std::cout << "\n" << "\n" << "Not enough money";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			system("cls");
			Shop(money, weapon, upgrade1, upgrade2, cost, pet);
		}
	}
	if (Text_Shop == "Buy weapon")
	{
		if (*money > pow(1.5, *upgrade1) * *cost)
		{
			*money -= pow(1.5, *upgrade1) * *cost;
			*weapon += 1;
			*upgrade1 += 1;
			system("cls");
			std::cout << "\n" << "\n" << "Thank you for your purchase";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			system("cls");
			Shop(money, weapon, upgrade1, upgrade2, cost, pet);
		}
		else
		{
			system("cls");
			std::cout << "\n" << "\n" << "Not enough money";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			system("cls");
			Shop(money, weapon, upgrade1, upgrade2, cost, pet);
		}
	}
	if (Text_Shop == "Back")
	{
		system("cls");
		return;
	}
	return;
}
void start_game(double* money, int* weapon, int* pet, double* cost, int* upgrade1, int* upgrade2, struct boss tom, struct  boss ivan)
{
	const auto n = 1;
	std::string m;
	while (n > -10)
	{
		to_spam(*money, *weapon, *pet);
		std::getline(std::cin, m);
		system("cls");
		if (m == "Shop")
		{
			Shop(money, weapon, upgrade1, upgrade2, cost, pet);
		}
		if (m == "Fight")
		{
			fight(*weapon, *pet, *money);
		}
		if (m == "Boss")
		{
			std::cout << "You have exactly one attempt to pass the test questions " <<"\n";
			std::this_thread::sleep_for(std::chrono::seconds(3));
			std::cout << "your attack in the boss fight(10*Weapon): " << 10 * *weapon << "\n";
			std::this_thread::sleep_for(std::chrono::seconds(3));
			std::cout << "Boss name : " << tom.name << "\n" << "Boss health: " << tom.health << "\n" << "Drop from the boss: " <<tom.drop << "\n";
			std::this_thread::sleep_for(std::chrono::seconds(3));
			if (tom.health < 10 * *weapon)
			{
				system("cls");
				std::cout << "________________________________________" << "\n";
				std::this_thread::sleep_for(std::chrono::seconds(3));
				std::cout << "There is an attack..." << "\n";
				std::this_thread::sleep_for(std::chrono::seconds(3));
				std::cout << "________________________________________" << "\n";
				std::this_thread::sleep_for(std::chrono::seconds(3));
				std::cout << "Fine. But that is not all";
				std::this_thread::sleep_for(std::chrono::seconds(3));
				system("cls");
				std::cout << "Boss name : " <<ivan.name << "\n" << "Boss health: " << ivan.health << "\n" << "Drop from the boss: " << ivan.drop << "\n";
				std::this_thread::sleep_for(std::chrono::seconds(3));
				if (ivan.health < 10 * *weapon)
				{
					*money += ivan.drop;
					*money += tom.drop;
					std::cout << "________________________________________" << "\n";
					std::this_thread::sleep_for(std::chrono::seconds(3));
					std::cout << "There is an attack..." << "\n";
					std::this_thread::sleep_for(std::chrono::seconds(3));
					std::cout << "________________________________________" << "\n";
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");
					std::cout << "YOU WON!!!" << "\n";
					std::cout << "YOU GOT: " << tom.drop + ivan.drop << "Money" << "\n";
					std::this_thread::sleep_for(std::chrono::seconds(5));
					system("cls");
				}
				else
				{
					std::cout << "________________________________________" << "\n";
					std::this_thread::sleep_for(std::chrono::seconds(3));
					std::cout << "There is an attack..." << "\n";
					std::this_thread::sleep_for(std::chrono::seconds(3));
					std::cout << "________________________________________" << "\n";
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");
					std::cout << "YOU LOSE!"<<"\n";
					*money += 15;
					std::cout << "YOU GOT: 15 POINTS FOR KW" << "\n";
					std::this_thread::sleep_for(std::chrono::seconds(5));

					system("cls");
				}
			}
			else
			{
				std::cout << "________________________________________" << "\n";
				std::this_thread::sleep_for(std::chrono::seconds(3));
				std::cout << "There is an attack..." << "\n";
				std::this_thread::sleep_for(std::chrono::seconds(3));
				std::cout << "________________________________________" << "\n";
				std::this_thread::sleep_for(std::chrono::seconds(3));
				system("cls");
				std::cout << "YOU LOSE!";
				*money += 24;
				std::cout << "YOU GOT: 24 POINTS FOR KW" << "\n";
				std::this_thread::sleep_for(std::chrono::seconds(5));
				system("cls");
			}

		}
		else
		{
			*money += *weapon;
		}
	}
	start_game(money, weapon, pet, cost,upgrade1, upgrade2, (boss(tom)), (boss(ivan)));
	return;
}

int main()
{
	boss tom{ "Timur_squire_gungsta",100,1000 };
	boss ivan{ "Ivan_SENSEI_GUNGSTA", 125,2000 };
	auto pet = 0;
	auto cost = 100.0;
	auto upgrade1 = 1;
	auto upgrade2 = 1;
	auto weapon = 15;
	auto money = 0.0;
	start_game(&money, &weapon, &pet, &cost, &upgrade1, &upgrade2, (boss(tom)), (boss(ivan)));
	return 0;
}
