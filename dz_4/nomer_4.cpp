#include<iostream>
enum class Month
{
	January,February,March,
	April,May,June,
	July,August,September,
	October,November,December
};
void monthTodays(Month month)
{
	switch (month)
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
		default:
			std::cout << "30\n";
	}
}




int main()
{
	monthTodays(Month(2));
}