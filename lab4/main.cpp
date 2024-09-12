//	сортировка расческой
#include<iostream>


int main() {

	size_t len;
	std::cin >> len;
	int* arr = new int[len];

	for (size_t i = 0; i < len; i++)
		std::cin >> arr[i];

	short step = len - 1;
	float div = 1.25f;

	while (step >= 1) {
		for (size_t i = 0; i < (len - step); i++) {
			if (arr[i] > arr[i + step])
				std::swap(arr[i], arr[i + step]);
		}
		step /= div;	//	уменьшаем расстояние между сравниваемыми элементами
	}

	for (size_t i = 0; i < len; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	return 0;
}