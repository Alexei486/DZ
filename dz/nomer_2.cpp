#include <iostream>
#include <vector>
int main() {
	std::vector<int> vec = { 7, -42, 5, 0, 16, -8 };
	for (int j = 1; j < vec.size(); j++) {
		int p = j;
		while (p > 0 && vec[p - 1] > vec[p]) {
			std::swap(vec[p - 1], vec[p]);
			p -= 1;
		}
	}
	for (int i = 0; i < vec.size(); i++) std::cout << "\n" << vec[i] << "\n";
	return 0;
}
