#include<iostream>

template<int N, int M>
struct F
{
	static inline constexpr auto value = F<N - 1, M - 1>::value + F<N - 1, M>::value;
};

template<int N>
struct F<N, N>
{
	static inline constexpr auto value = 1;
};

template<int N>
struct F<N, 0>
{
	static inline constexpr auto value = 1;
};

int main()
{
	std::cout << F<3, 1>::value;
	return 0;
}