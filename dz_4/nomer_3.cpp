#include<iostream>

struct times
{
	int year : 12;
	int month : 5;
	int day : 6;
	int H : 7;
	int min : 7;
	int sec : 6;
	int msec : 10;
};
void printInformation(times good)
{
	std::cout << "Data1: "<<good.year<<":" << good.month << ":" << good.day << ":" << good.H << ":" << good.min<< ":" << good.sec << ":" << good.msec << ":";
}
int main()
{
	times day1{  2021,12,31,57,59,2,134 };
	printInformation(day1);

}