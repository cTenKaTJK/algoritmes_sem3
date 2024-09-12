//	сортировка вставкой
#include <iostream>

int main() {

	size_t len;
	std::cin >> len;
	int* arr = new int[len];

	for (size_t i = 0; i < len; i++)
		std::cin >> arr[i];

	for (size_t i = 1; i < len; i++) {
		size_t j = i;
		while (arr[j - 1] > arr[j]) {	//	ищем место для элемента спереди списка
			std::swap(arr[j - 1], arr[j]);
			j--;
		}
	}

	for (size_t i = 0; i < len; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	return 0;
}