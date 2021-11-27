#include "Snack.h"
#include <cmath>

template <typename T>
const T& max(const T& a, const T& b)
{
	return (a > b) ? a : b;
}
double Snack::price() const
{
	auto m_t=max(m_a, m_b);
	return 2 * std::sqrt((m_t) * 3);
}

std::string Snack::toString() const
{
	return "Snack(" + std::to_string(m_a), +", " + std::to_string(m_b) + ")";
}
