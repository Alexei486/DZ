#pragma once
#include "Shop.h"
class Snack : public Goods
{
public:
	Snack(double a, double b) :
		m_a(a), m_b(b) {}
	double price() const override;
	std::string toString() const override;
protected:
	double m_a;
	double m_b;
};

