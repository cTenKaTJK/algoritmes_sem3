#include <iostream>
#include <vector>
#include <string>


bool in(char el, std::string str) {
	for (size_t i = 0; i < str.length(); i++)
		if (el == str[i]) return true;
	return false;
}

template <typename T>
void print(std::vector<T> vec ) {
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << '\n';
}


int main() {

	std::string nums = "0123456789";
	std::string opert = "+-*/";

	std::vector<char> operatrs;
	std::vector<char> operands;
	std::string line;

	std::cin >> line;

	for (size_t i = 0; i < line.length(); i++) {
		if (in(line[i], nums)) operands.push_back(line[i]);
		if (in(line[i], opert)) operatrs.push_back(line[i]);
	}

	while (operatrs.size() > 0) {
		print<char>(operands);
		print<char>(operatrs);

		int a, b;
		char c;


	}

	return 0;
}