#include <iostream>
#include <type_traits>

struct A {
    int abc() const&;
};
int f();

template<typename T>
struct is_function : std::false_type { };

template<typename T, typename ... Types >
struct is_function<T(Types...)> : std::true_type {};

template<typename T, typename ... Types >
struct is_function<T(Types...) const> : std::true_type {};

template<typename T, typename ... Types>
struct is_function< T(Types...)&> : std::true_type {};

template<typename T, typename ... Types >
struct is_function< T(Types...) const&> : std::true_type {};

template<typename T, typename ... Types >
struct is_function<T(Types...)&&> : std::true_type {};

template<typename T, typename ... Types >
struct is_function<T(Types...) const&&> : std::true_type {};

template <typename f>
inline const bool is_function_v = is_function <f> ::value;

int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_function<A>::value << '\n';
    std::cout << std::is_function<decltype(f)>::value << '\n';
    std::cout << is_function_v<decltype(f)> << '\n';
    std::cout<< is_function_v <int(double, char) const >;
    return 0;
}


