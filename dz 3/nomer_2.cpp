#include <iostream>
#include <functional>
#include <vector>
double calculate(double x1, double x2, std::function < double(double, double)>a)
{
	return a(x1, x2);
}

int main()
{
	double x1 = 1.23;
	double x2 = 4.56;
	std::vector <std::function < double(double, double) >> function { [](double x1, double x2) {return x1 + x2; } ,[](double x1, double x2) {return x1 * x2; },[](double x1, double x2) {return x1 - x2; }, [](double x1, double x2) {return x1 / x2; } };
	for (auto dd:function)
	{
		std::cout << calculate(x1,x2,dd)<< std::endl;
	}
	return 0;
}
