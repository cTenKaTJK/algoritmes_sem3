//	сортировка Шелла
#include <iostream>


int main() {

	size_t len;
	std::cin >> len;
	int* arr = new int[len];

	for (size_t i = 0; i < len; i++)
		std::cin >> arr[i];

	for (int step = len / 2; step > 0; step /= 2) {	//	шаг уменьшается в два раза
		for (int i = step; i < len; ++i) {
			for (int j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step)
				std::swap(arr[j], arr[j + step]);
		}
	}


	for (size_t i = 0; i < len; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	return 0;
}