#pragma once


namespace hh {

	struct cell {
		std::string str;
		cell* node;
		cell(std::string val_) : str(val_), node(nullptr) {}
	};

	struct list {
		cell* first;
		cell* last;

		list() : first(nullptr), last(nullptr) {}

		bool is_empty() { return first == nullptr; }

		void add(std::string _val) {
			cell* p = new cell(_val);
			if (is_empty()) {
				first = p;
				last = p;
				return;
			}
			last->node = p;
			last = p;
		}

		std::string out() {
			if (is_empty()) return "";
			cell* p = first;
			std::string line = "";
			while (p) {
				line += p->str + " ";
				p = p->node;
			}
			return line;
		}
	};


	class HashTab {
	private:
		int size_;
		list* tab_;

	public:
		HashTab(int size) {
			size_ = size;
			tab_ = new list[size_];
		}

		~HashTab() {

		}

		int size() { return size_; }

		void add(std::string elem) {
			int hash = HashFunc(elem, size_);
			tab_[hash].add(elem);

		}

		void print() {
			for (int i = 0; i < size_; i++)
				std::cout << i << '\t' << tab_[i].out() << '\n';
		}

		void fileout(std::string filename) {
			std::ofstream write(filename);
			for (int i = 0; i < size_; i++)
				write << i << '\t' << tab_[i].out() << '\n';
		}

		int HashFunc(std::string& word, int tab_size) {
			int hash = 0;
			for (int i = 0; i < word.length(); i++)
				hash += int(word[i]);
			hash %= tab_size;
			return hash;
		}
	};


	void read_n_write(std::string in_file, std::string out_file, int tab_size) {
		HashTab H(tab_size);
		std::ifstream read(in_file);
		std::string line;
		if (read.is_open()) {
			int counter = 0;
			while (read >> line) {
				H.add(line);
				counter++;
			}
		}
		H.fileout(out_file);
		H.print();
	}

}