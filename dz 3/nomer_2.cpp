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
	int b;
	std::cin >>b;
	double x1 = 1.23;
	double x2 = 4.56;
	std::vector <std::function < double(double, double) >> vec;
	vec.push_back(mem);
	vec.push_back(mem1);
	vec.push_back(mem2);
	vec.push_back(mem3);
	std::cout << (vec[b])(x1, x2);
}