// сортировка пиармидой (бинарная куча)
#include <iostream>


void heaping(int arr[], size_t len, size_t i) {	// построение ветви бинарного дерева
	size_t max_id = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < len && arr[left] > arr[max_id])
		max_id = left;
	if (right < len && arr[right] > arr[max_id])
		max_id = right;
	if (max_id != i) {
		std::swap(arr[i], arr[max_id]);
		heaping(arr, len, max_id);	// рекурсия
	}
}


int main() {

	size_t len;
	std::cin >> len;
	int* arr = new int[len];

	for (size_t i = 0; i < len; i++)
		std::cin >> arr[i];

	for (int i = len / 2 - 1; i >= 0; i--)	// изначальная куча
		heaping(arr, len, i);
	for (int i = len - 1; i >= 0; i--){
		std::swap(arr[0], arr[i]);
		heaping(arr, i, 0);	// построение более маленьких подкуч
	}

	for (size_t i = 0; i < len; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	return 0;
}