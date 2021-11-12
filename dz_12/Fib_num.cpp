#include<iostream>

template<int N>
struct F
{
	static constexpr auto value = F<N - 1>::value + F<N - 2>::value;
};
template<>
struct F<0>
{
	static constexpr auto value = 1;
};
template<>
struct F<1>
{
	static constexpr auto value = 1;
};
int main()
{
	std::cout << F<9>::value;
	return 0;
}