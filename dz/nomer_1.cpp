#include <iostream>
#include <vector>
#include <string>
void main() {
	std::string all = "";
	getline(std::cin, all);
	std::vector<std::string> v_1;
	std::string txt = "";
	for (int i = 0; i < all.size(); i++) {
		if (all[i] == ' ') {
			v_1.push_back(txt);
			txt = "";
		}
		txt = txt + all[i];
	}
	if (txt != "") v_1.push_back(txt);

	for (int i = 0; i < v_1.size(); i++) std::cout << "\n" << v_1[i] << "\n";
}