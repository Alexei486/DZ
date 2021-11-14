#include <iostream>

template < bool t, typename true_type>
struct enable_if
{
	using type = true_type;
};

template < typename true_type >
struct enable_if < false, true_type >
{
};

template < bool T, typename TT >
using enable_if_t = enable_if < T, TT >;

int main() 
{

	return 0;
}