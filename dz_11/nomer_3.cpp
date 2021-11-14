#include <iostream>
#include <type_traits>

//nomber_1
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

//https://en.cppreference.com/w/cpp/types/remove_extent
template<typename t>
struct remove_extent
{
    using type = t;
};

template<typename t>
struct remove_extent<t[]>
{
    using type = t;
};

template<typename t, std::size_t n>
struct remove_extent<t[n]>
{
    using type = t;
};

template<typename t>
using remove_extent_t = remove_extent<t>::type;


//https://en.cppreference.com/w/cpp/types/is_array
template<typename t>
struct is_array : std::false_type {};

template<typename t>
struct is_array<t[]> : std::true_type {};

template<typename t, std::size_t n>
struct is_array<t[n]> : std::true_type {};

template <typename t >
inline const bool is_array_v = is_array<t>::value;


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

template <typename T>
struct decay
{
    using TT = std::remove_reference_t<T>;
    using Type = if_then_else_t<is_function<TT>, TT*,
        if_then_else_t<is_array<TT>, remove_extent_t<TT>*, TT>>;
};

template <typename T>
using decay_t = decay<T>;

int main()
{
    std::cout << std::boolalpha << std::is_same<int*, decay_t<int[]>>::value;
}