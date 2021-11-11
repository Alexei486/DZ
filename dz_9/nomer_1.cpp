#include<iostream>
#include <tuple>
#include <any>
//comment out the necessary

//with convolution
#include<iostream>
#include <tuple>
#include <any>
template < typename ... Types >
void print(Types ... args)
{
	(std::cout << (... + sizeof(args)) << std::endl);
}
int main()
{
	print(1, 2, 3, 345, 9.0);
}


//without convolution
template <typename T>
size_t count(T arg)
{
	return sizeof(arg);
}
template <typename T, typename ... Types >
size_t count(T arg,Types ... args)
{
	return sizeof(arg) + count(args...);
}
int main()
{
	std::cout<<count(1, 2, 3, 345, 9.0);
}
