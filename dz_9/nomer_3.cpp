#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <any>

template < typename T, typename ... Types >
auto print(T function, Types ... args)
{
	function(args...);
}
void summ(int x, double y)
{
	std::cout << x + y << std::endl;
}
int main()
{
	print(summ, 1, 9.5);
	return 0;
}