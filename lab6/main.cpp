//	сортировка выбором
#include <iostream>


int main() {

	size_t len;
	std::cin >> len;
	int* arr = new int[len];

	for (size_t i = 0; i < len; i++)
		std::cin >> arr[i];

	for (size_t i = 0; i < len - 1; i++) {
		size_t minId = i;
		for (size_t j = i; j < len; j++) {	//	находим индекс минимального числа среди неотсортированных
			if (arr[j] < arr[minId]) minId = j;
		}
		if (minId != i) std::swap(arr[i], arr[minId]);	//	вставляем его в начало неотсортированной части
	}

	for (size_t i = 0; i < len; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	return 0;
}
