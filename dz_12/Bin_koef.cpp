#include<iostream>

template<int N,int M>
struct F
{
	static inline constexpr auto value = F<N - 1, M - 1>::value +F<N - 1, M>::value;
};
template<>
struct F<0, 0>
{
	static inline constexpr auto value = 1;
};
template<int M>
struct F<0, M>
{
	static inline constexpr auto value = 0;
};
int main()
{
	std::cout << F<6, 3>::value;
	return 0;
}