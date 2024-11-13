#include<iostream>
#include<fstream>
#include<string>
#include"add.hpp"


int main() {
	setlocale(LC_ALL, "");
	int tab_size = 5;
	std::string in_file = "./src/input.txt";
	std::string out_file = "./src/output.txt";

	hh::read_n_write(in_file, out_file, tab_size);

	return 0;
}