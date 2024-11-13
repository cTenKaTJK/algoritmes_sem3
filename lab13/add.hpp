#pragma once


namespace hh {

	class HashTab {
	private:
		int size_;
		std::string* tab_;

	public:
		HashTab(int size) {
			size_ = size;
			tab_ = new std::string[size_];
			for (int i = 0; i < size; i++) tab_[i] = "";
		}

		~HashTab() {}

		int size() { return size_; }

		void add(std::string elem) {
			int hash = HashFunc(elem, size_);
			while (tab_[hash] != "") {
				hash = HashFunc2(hash, size_);
			}
			tab_[hash] = elem;
		}

		void print() {
			for (int i = 0; i < size_; i++)
				std::cout << i << '\t' << tab_[i] << '\n';
		}

		void fileout() {
			std::ofstream write("./src/output.txt");
			for (int i = 0; i < size_; i++)
				write << i << '\t' << tab_[i] << '\n';
		}

		int HashFunc(std::string& word, int tab_size) {
			int hash = 0;
			for (int i = 0; i < word.length(); i++)
				hash += int(word[i]);
			hash %= tab_size;
			return hash;
		}

		int HashFunc2(int old_hash, int tab_size) {
			return (old_hash + 1) % tab_size;
		}
	};

	void read(std::string filename, int tab_size) {
		HashTab H(tab_size);
		std::ifstream read(filename);
		std::string line;
		if (read.is_open()) {
			int counter = 0;
			while (read >> line) {
				if (counter >= H.size()) {
					std::cout << "There are no free places here!	Started from word: " << line;
					break;
				}
				H.add(line);
				counter++;
			}
		}
		H.fileout();
		H.print();
	}

}