#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <any>
template<typename T,typename... Args>
T* func(Args ... args)
{
	return new T(args...);
}
int main()
{
	auto kek = func<int>(5);
	std::cout << *kek;
	delete[] kek;
	return 0;
}
