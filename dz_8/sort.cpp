#include <iostream>
#include <vector>
template<typename T, size_t N>
void TopDownMerge(T(&array)[N] ,int iBegin, int iMiddle, int iEnd)
{
	int i = iBegin, j = iMiddle;
	int B_COPY = iEnd - iBegin;
	std::vector <int> B(B_COPY);
	for (auto k = 0; k < B_COPY; ++k)
	{
		if (i < iMiddle && (j >= iEnd || array[i] <= array[j]))
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
template<typename T,size_t N>
void TopDownSplitMerge(T(&array)[N],int left, int right)
{
	if (right - left <= 1)
	{
		return;
	}
	int middle = (left + right) / 2;
	TopDownSplitMerge(array,left, middle );
	TopDownSplitMerge(array,middle, right );
	TopDownMerge(array, left, middle, right);
}
int main()
{
	int a[6] = { 7, -42, 5, 0, 16, -8 };
	TopDownSplitMerge(a, 0, 6);
	for (int i = 0; i < 6; ++i)
	{
		std::cout << a[i]<<"\n";
	}
	return 0;
}