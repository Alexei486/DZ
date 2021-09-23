#include <iostream>
#include <functional>
#include <vector>
double calculate(double x1, double x2, std::function < double(double, double)> A)
{
	return A(x1, x2);
}

int main()
{
	auto mem = [](double x1, double x2) {return x1 + x2; };
	auto mem1 = [](double x1, double x2) {return x1 * x2; };
	auto mem2 = [](double x1, double x2) {return x1 - x2; };
	auto mem3 = [](double x1, double x2) {return x1 / x2; };
	double x1 = 1.23;
	double x2 = 4.56;
	std::vector <std::function < double(double, double) >> function { mem,mem1,mem2,mem3 };
	for (auto &dd:function)
	{
		std::cout << calculate(x1,x2,dd)<< std::endl;
	}
	return 0;
}
