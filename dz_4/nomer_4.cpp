#include<iostream>
enum class Month
{
	January = 1, February, March,
	April, May, June,
	July, August, September,
	October, November, December
};
void monthTodays(const int month)
{

	switch (static_cast<Month>(month))
	{
	case Month::January:
	case Month::March:
	case Month::May:
	case Month::July:
	case Month::August:
	case Month::October:
	case Month::December:
		std::cout << "31\n";
		break;
	case Month::February:
		std::cout << "28\n";
		break;
	case Month::April:
	case Month::June:
	case Month::September:
	case Month::November:
		std::cout << "30\n";
		break;
	default:
		std::cout << "ERROR";
	}
}




int main()
{
	int lol;
	std::cin >>lol;
	monthTodays(lol);
}
