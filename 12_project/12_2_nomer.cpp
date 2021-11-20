#include<iostream>

constexpr double factorial(int n)
{
    double res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

constexpr double e(int n)
{
    double res = 1;
    for (int i = 1; i <= n; ++i)
    {
        res += 1 / factorial(i);
    }
    return res;
}

int main()
{
    constexpr auto res = e(15);
    std::cout << res << std::endl;
    return 0;
}