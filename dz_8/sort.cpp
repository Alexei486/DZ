#include <iostream>
#include <vector>
template<typename T, size_t N,typename F>
void TopDownMerge(T(&array)[N], int iBegin, int iMiddle, int iEnd, F func)
{
	int i = iBegin, j = iMiddle;
	int B_COPY = iEnd - iBegin;
	std::vector <int> B(B_COPY);
	for (auto k = 0; k < B_COPY; ++k)
	{
		if (i < iMiddle && (j >= iEnd || func(array[i], array[j])))
		{
			B[k] = array[i];
			++i;
		}
		else
		{
			B[k] = array[j];
			++j;
		}
	}
	for (auto j = 0; j < B_COPY; ++j)
	{
		array[iBegin + j] = B[j];
	}
}
template<typename T, size_t N, typename F>
void TopDownSplitMerge(T(&array)[], int left, int right, F func)
{
	if (right - left <= 1)
	{
		return;
	}
	int middle = (left + right) / 2;
	TopDownSplitMerge(array, left, middle, func);
	TopDownSplitMerge(array, middle, right, func);
	TopDownMerge(array, left, middle, right,func);
}
int main()
{
	int a[6] = { 7, -42, 5, 0, 16, -8 };
	TopDownSplitMerge(a, 0, 6, [](int a, int b) {return a <= b; });
	for (int i = 0; i < 6; ++i)
	{
		std::cout << a[i] << "\n";
	}

	int* b = new int[7]{ 7, -42, 5, 0, 16, -8 };
	TopDownSplitMerge(b, 0, 4, [](int a, int b) {return a <= b; });
	for (auto i = 0; i <6; i++)
	{
		std::cout << b[i] << std::endl;
	}
		
	return 0;
}
