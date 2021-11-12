#include <iostream>
#include <string>
//with functions
/*
constexpr double factorial(int n)
{
    if (n == 1) {
        return 1.0;
    } else {
        return factorial(n - 1) * n;
    }
}

constexpr double e(int n)
{
    if (n == 0) {
        return 1.0;
    }
    return e(n - 1) + 1 / factorial(n);
}

int main()
{
    constexpr auto res = e(15);
    std::cout << res << std::endl;
    return 0;
}

*/

//with no functions
template<size_t N>
struct Factorial
{
    static inline constexpr auto value = Factorial<N - 1>::value * N;
};

template<>
struct Factorial<1>
{
    static inline constexpr auto value = 1.0;
};

template<size_t N>
struct Exp
{
    static inline constexpr auto value = Exp<N - 1>::value + 1 / Factorial<N>::value;
};

template<>
struct Exp<0>
{
    static inline constexpr auto value = 1.0;
};

int main()
{
    std::cout << Exp<25>::value << std::endl;
    return 0;
}
