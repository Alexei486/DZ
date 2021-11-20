#include <iostream>
#include <type_traits>

// IS FUNCTION

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

template <typename F>
inline const bool is_function_v = is_function <F> ::value;


// REMOVE CONST

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
template <typename T>
using remove_const_t = typename remove_const <const T>::type;

// REMOVE EXTENT
// https://en.cppreference.com/w/cpp/types/remove_extent

template<typename T>
struct remove_extent
{
    using type = T;
};

template<typename T>
struct remove_extent<T[]>
{
    using type = T;
};

template<typename T, std::size_t N>
struct remove_extent<T[N]>
{
    using type = T;
};

template<typename T>
using remove_extent_t = typename remove_extent<T>::type;

// REMOVE REFERENCE

template < typename T > 
struct remove_reference 
{ 
    using type = T; 
};

template < typename T > 
struct remove_reference<T&> 
{ 
    using type = T; 
};

template < typename T > 
struct remove_reference<T&&> 
{ 
    using type = T; 
};

template <typename T >
using remove_reference_t = typename remove_reference<T>::type;

// IS ARRAY

//https://en.cppreference.com/w/cpp/types/is_array
template<typename T>
struct is_array : std::false_type {};

template<typename T>
struct is_array<T[]> : std::true_type {};

template<typename T, std::size_t N>
struct is_array<T[N]> : std::true_type {};

template <typename T>
inline const bool is_array_v = is_array<T>::value;

// IF THEN ELSE

template < bool C, typename True_Type, typename False_Type >
struct if_then_else
{
    using type = True_Type;
};

template < typename True_Type, typename False_Type >
struct if_then_else < false, True_Type, False_Type >
{
    using type = False_Type;
};

template < bool C, typename TT, typename FT >
using if_then_else_t = typename if_then_else < C, TT, FT >::type;

// DECAY

template <typename T>
struct decay
{
    using type = if_then_else_t <is_function_v<T>, std::add_pointer_t<T>,
        if_then_else_t <is_array_v<T>, std::add_pointer_t<remove_extent_t<T>>, 
        remove_const_t<remove_reference_t<T>> > >;
};

template <typename T>
using decay_t = typename decay<T>::type;


int main()
{
    std::cout << std::boolalpha
        << std::is_same_v<decay_t<int>, int> << '\n'
        << std::is_same_v<decay_t<int&>, int> << '\n'
        << std::is_same_v<decay_t<int&&>, int> << '\n'
        << std::is_same_v<decay_t<const int&>, int> << '\n'
        << std::is_same_v<decay_t<int[2]>, int*> << '\n'
        << std::is_same_v<decay_t<int(int)>, int(*)(int)> << '\n';
}