#include <iostream>
#include <vector>
#include <algorithm>
std::vector <int> ascending(std::vector <int> vec)
{
    [&vec]()
    {
        std::sort(std::begin(vec), std::end(vec), [](int a, int b) {return a > b; });
    }();
    for (auto i : vec) {std::cout << i << " ";}
    return (vec);
}
std::vector <int>  descending(std::vector <int> vec)
{
    [&vec]() {std::sort(std::begin(vec),std::end(vec), [](int a, int b) {return a < b;});
    }();
    for (auto i : vec) { std::cout << i << " "; };
    return (vec);
}
int main()
{
	std::vector<int> vec = { 7, -42, 5, 0, 16, -8 };
    ascending(vec);
    descending(vec);
	return 0;
}
