// поразрядная сортировка
#include <iostream>
#include <vector>


int nl(int x) {	// число разрядов в числе
	size_t len = 0;
	while (x > 0) {
		x /= 10;
		len++;
	}
	return len;
}

int digt(int x, size_t place) {	// цифра в разряде
	for (size_t i = 1; i < place; i++) {
		if (x > 0) x /= 10;
		else return 0;
	}
	return x % 10;
}


int main() {

	size_t len;
	std::cin >> len;
	int* arr = new int[len];

	for (size_t i = 0; i < len; i++)
		std::cin >> arr[i];

	size_t max_len = 0;
	for (size_t i = 0; i < len; i++)
		max_len = nl(arr[i]) > max_len ? max_len = nl(arr[i]) : max_len;
	for (size_t pl = 0; pl < max_len; pl++) {
		std::vector<int> base[10];	// создание и заполнения массива элементами по цифре в их текущем разряде
		for (size_t i = 0; i < len; i++) {
			base[digt(arr[i], pl)].push_back(arr[i]);
		}
		size_t cntr = 0;
		for (size_t i = 0; i < 10; i++) {	// запись по новому порядку в исходный массив
			for (size_t j = 0; j < base[i].size(); j++) {
				arr[cntr] = base[i][j];
				cntr++;
			}
		}
	}


	for (size_t i = 0; i < len; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	return 0;
}