#include <iostream>
#include <functional>
#include <vector>
std::function < double(double, double) > mem = [](double x1, double x2)
{
	return x1 + x2;
};
std::function < double(double, double) > mem1 = [](double x1, double x2)
{
	return x1 * x2;
};
std::function < double(double, double) > mem2 = [](double x1, double x2)
{
	return x1 - x2;
};
std::function < double(double, double) > mem3 = [](double x1, double x2)
{
	return x1 / x2;
};
int main()
{
	double x1 = 1.23;
	double x2 = 4.56;
	std::vector <std::function < double(double, double) >> functions{ mem,mem1,mem2,mem3 };
	std::cout << (mem)(x1, x2) << std::endl;
	std::cout << (mem1)(x1, x2) << std::endl;
	std::cout << (mem2)(x1, x2) << std::endl;
	std::cout << (mem3)(x1, x2) << std::endl;
	return 0;
}
