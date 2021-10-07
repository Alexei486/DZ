#include<iostream>

struct times
{
	unsigned int year : 11;
	unsigned int month : 4;
	unsigned int day :5;
	unsigned int H : 6;
	unsigned int min : 6;
	unsigned int sec : 6;
	unsigned int msec : 10;
};
void printInformation(times good)
{
	std::cout << "Data1: " << good.year << ":" << good.month << ":" << good.day << ":" << good.H << ":" << good.min << ":" << good.sec << ":" << good.msec << std::endl;
}
int main()
{
	times day1{ 2020,11,30,58,58,58,998 };
	printInformation(day1);
}
