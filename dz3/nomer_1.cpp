#include <iostream>
#include<functional>

int fb(int n,int a0=1,int a1=1)
{
	return (n > 0) ? fb(--n, a1, a0 + a1) : a0;
}
int main()
{
	std::cout<<fb(2);
	return 0;
}
