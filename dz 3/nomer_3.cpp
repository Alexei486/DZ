#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec = { 7, -42, 5, 0, 16, -8 };
    [&vec](){std::sort(std::begin(vec), std::end(vec), [](auto a, auto b) {return a > b; });}();
    for (auto i : vec) { std::cout << i << " "; }
    [&vec]() {std::sort(std::begin(vec), std::end(vec), [](auto a,auto b) {return a < b; });}();
    for (auto i : vec) { std::cout << i << " "; };
    return 0;
}
