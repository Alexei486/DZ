#include "Nuts.h"
#include <cmath>

double Nuts::price() const
{
	return 2 *std::sqrt((m_a + m_b) * 2);
}

std::string Nuts::toString() const
{
	return "Nuts(" + std::to_string(m_a), +", " + std::to_string(m_b) + ")";
}
