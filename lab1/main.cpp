#include <iostream>
#include <string>
#include <vector>


bool in(char sym, std::string str) {
	for (size_t i = 0; i < str.length(); i++)
		if (str[i] == sym) return true;
	return false;
}

size_t id(char sym, std::string str) {
	for (size_t i = 0; i < str.length(); i++)
		if (str[i] == sym) return i;
}

size_t id(char sym, std::vector<char> str) {
	for (size_t i = 0; i < str.size(); i++)
		if (str[i] == sym) return i;
}

enum class Scopes {NO, NRML, SQ, FG, TRNG};


int main() {

	std::string op_s = "([{<";
	std::string ed_s = ")]}>";

	std::string str;
	std::cin >> str;

	std::vector<char> scopes;

	for (size_t i = 0; i < str.length(); i++) {
		if (in(str[i], op_s))
			scopes.push_back(str[i]);
		else if (in(str[i], ed_s) && scopes.size() == 0) {
			scopes.push_back('!');
			break;
		}
		else if (in(str[i], ed_s) && (id(str[i], ed_s) == id(scopes.back(), op_s)))
			scopes.pop_back();
	}

	if (scopes.size() != 0) std::cout << "WRONG\n";
	else std::cout << "RIGHT!\n";

	return 0;
}