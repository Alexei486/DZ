#include <iostream>
#include<functional>
int fb(int n)
{
	if (n > 1)
	{

		return (fb(n - 1) + fb(n - 2));
	}
	else
	{
		return 1;
	}
}
int main()
{
	for (int i = 0; 15; i++)
	{
		std::cout << fb(i)<< " ";
	}
	return 0;
}