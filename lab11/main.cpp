#include <iostream>


int partition(int left, int right, int* arr) {
	int base = arr[left + (right - left) / 2];
	int middle = left;
	for (int i = left; i < right; i++) {
		if (arr[i] < base) {
			std::swap(arr[i], arr[middle]);
			middle++;
		}
	}
	return middle;
}


void sort(int left, int right, int* arr) {
	if ((right - left) == 1) return;
	int middle = partition(left, right, arr);
	sort(left, middle, arr);
	sort(left, middle, arr);
}


int main()
{
	int n;
	std::cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) std::cin >> arr[i];
	sort(0, n, arr);
	for (int i = 0; i < n; i++) std::cout << arr[i];
	return 0;
}