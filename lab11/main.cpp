#include <iostream>


int supp(int left, int right, int* arr) {
	int base = arr[left + (right - left) / 2];
	std::cout << "!!!" << base << '\n';
	int i = left, j = right;
	while (true) {
		while (arr[i] < base) i++;

		while (arr[j] > base) j--;

		if (i >= j) return j;

		std::swap(arr[i++], arr[j--]);
	}
}


void sort(int left, int right, int* arr) {
	if (left >= right) return;
	auto middle = supp(left, right, arr);
	std::cout << arr[left] << ' ' << arr[middle] << ' ' << arr[right] << '\n';
	sort(left, middle, arr);
	sort(middle + 1, right, arr);
}


int main()
{
	int n;
	std::cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) std::cin >> arr[i];
	sort(0, n - 1, arr);
	for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
	return 0;
}
