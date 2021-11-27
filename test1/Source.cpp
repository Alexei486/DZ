#include<iostream>
#include <tuple>
#include <any>
#include "Shop.h"
int main() 
{
	std::vector <Goods*> set_of_goods;
	int price1 = Nuts(1, 4) ;
	int price2 = Snack(3, 6);
	set_of_goods.push_back(price1);
	set_of_goods.push_back(price2);
	return(0);
}