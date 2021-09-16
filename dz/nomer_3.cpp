#include <iostream>
#include <vector>
int main() {
	std::vector<int> vec = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,100,134,23423,2302222,3452334,6322327 };
	int help = 0;//����
	int left = 0;
	int mid = -1;
	int right = std::size(vec);
	while (left < right && left != mid)
	{
		mid = (left + right) / 2;
		if (vec[mid] <= help)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	std::cout << vec[mid];

	return 0;
}