#include <iostream>
#include "Header.h"

void Energy::jouli(int value)
{
	jouls = value;
	ergs = jouls * wsego;
	evs = jouls / e;
	std::cout << jouls << " " <<ergs <<" "<< evs;
}
void Energy::ev(int value)
{
	evs = value;
	jouls = evs * e;
	ergs = jouls * wsego;
}
void Energy::ergi(int value)
{
	ergs = value;
	jouls = ergs / wsego;
	evs = jouls / e;
}

int main()
{
	Energy kawo;
	kawo.jouli(1);
}