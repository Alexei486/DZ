#include<iostream>
#include<vector>
#include <iostream>
#include <array>

constexpr int sum( int n)
{
	int EN = n;
	int mem = 0;
	int en = 1000000;
	int* a = new int[en + 1];
	for (int i = 0; i <= en; i++)
		a[i] = i;
	for (int i = 2; i * i <= en; i++)
	{
		if (a[i])
			for (int j = i * i; j <= en; j += i)
				a[j] = 0;
	}
	int N = 0;
	for (int i = 2; i < en; i++)
	{
		if (a[i])
		{
			N += 1;
			if (N == EN)
			{
				mem=a[i];
			}

		}
	}
	delete[] a; 
	return(mem);
}
constexpr void func()
{
	constexpr int n = 10;
	constexpr int c = sum(n);
	std::cout << c;
}
int main()
{
	func();
	return 0;
}