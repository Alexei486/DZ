#include <iostream>
struct foo
{
	void m() { std::cout << "Non-Const\n"; }
	void m() const { std::cout << "Const\n"; }
};

template < typename T >
struct remove_const
{
	using type = T;
};

template < typename T >
struct remove_const < const T >
{
	using type = T;
};

template < typename T >
struct add_const
{
	using type = const T;
};

template <typename T>
using remove_const_t = remove_const <const T>;

template <typename T>
using add_const_t = add_const <T>;

int main()
{
	foo{}.m();
	std::add_const<foo>::type{}.m();
	std::remove_const<foo>::type{}.m();
	std::cout << std::boolalpha << std::is_same <int, add_const_t<int>>::value << std::endl;
	std::cout << std::boolalpha << std::is_same <const int, remove_const_t<const int>>::value;
	return 0;
}