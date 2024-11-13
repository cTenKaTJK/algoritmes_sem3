#include<iostream>
#include<fstream>
#include<string>
#include"add.hpp"


int main() {
	setlocale(LC_ALL, "");
	int tab_size = 10;
	std::string in_file = "./src/input.txt";

	hh::read(in_file, tab_size);

	return 0;
}