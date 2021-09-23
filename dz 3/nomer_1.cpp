#include <iostream>
#include<functional>
int fb(int n)
{
	return (n => 1) ?  fib(n - 1) + fib(n - 2) : 1;
}
int main()
{
	for (int i = 0; 15; i++)
	{
		std::cout << fb(i)<< " ";
	}
	return 0;
}
