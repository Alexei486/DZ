#include <iostream>
#include <functional>
#include <vector>

int main()
{
	auto mem = [](double x1, double x2) {return x1 + x2; };
	auto mem1 = [](double x1, double x2) {return x1 * x2; };
	auto mem2 = [](double x1, double x2) {return x1 - x2; };
	auto mem3 = [](double x1, double x2) {return x1 / x2; };
	double x1 = 1.23;
	double x2 = 4.56;
	std::vector <std::function < double(double, double) >> calculate { mem,mem1,mem2,mem3 };
	for (int i = 0; i < 4; i++)
	{
		std::cout << calculate[i](x1, x2) << std::endl;
	}
	return 0;
}
