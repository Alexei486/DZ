#pragma once


class Energy
{
public:
	void jouli(int value);
	void ergi(int value);
	void ev(int value);

private:
	double jouls, ergs, evs;
	const double e = 1.6e-19, wsego = 1e7;
};