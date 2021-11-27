#pragma once
#include <vector>
#include<string>
#include<cmath>
class consts {
	double const koef = 1.5;
};

struct Goods_data : public consts {
	double x, y;
	std::string toString() const
	{
		return "x=" + std::to_string(x) + "\n" + "y=" + std::to_string(y);
	}

};


class Goods {
public:
	Goods() = default;
	virtual ~Goods() = default;
	virtual double price() const = 0;
	virtual std::string toString() const = 0;
};