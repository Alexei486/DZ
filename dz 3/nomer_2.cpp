#include <iostream>
#include <functional>
#include <vector>

int main()
{
	std::function < double(double, double) > mem = [](double x1, double x2) {return x1 + x2; };
	std::function < double(double, double) > mem1 = [](double x1, double x2) {return x1 * x2; };
	std::function < double(double, double) > mem2 = [](double x1, double x2) {return x1 - x2; };
	std::function < double(double, double) > mem3 = [](double x1, double x2) {return x1 / x2; };
	double x1 = 1.23;
	double x2 = 4.56;
	std::vector <std::function < double(double, double) >> functions{ mem,mem1,mem2,mem3 };
	for (int i = 0;i<4; i++)
	{
		std::cout << functions[i](x1,x2)<<std::endl;
	}
	return 0;
}
