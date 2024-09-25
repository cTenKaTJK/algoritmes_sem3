#include <iostream>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>


void sort(int array[], std::size_t size) {
    if (size > 1) {
        std::size_t const left_size = size / 2;
        std::size_t const right_size = size - left_size;

        sort(&array[0], left_size);
        sort(&array[left_size], right_size);

        std::size_t lidx = 0, ridx = left_size, idx = 0;
        std::unique_ptr<int[]> tmp_array(new int[size]);

        while (lidx < left_size || ridx < size) {
            if (array[lidx] < array[ridx]) {
                tmp_array[idx++] = std::move(array[lidx]);
                lidx++;
            }
            else {
                tmp_array[idx++] = std::move(array[ridx]);
                ridx++;
            }

            if (lidx == left_size) {
                std::copy(std::make_move_iterator(&array[ridx]),
                    std::make_move_iterator(&array[size]),
                    &tmp_array[idx]);
                break;
            }
            if (ridx == size) {
                std::copy(std::make_move_iterator(&array[lidx]),
                    std::make_move_iterator(&array[left_size]),
                    &tmp_array[idx]);
                break;
            }
        }

        std::copy(std::make_move_iterator(tmp_array.get()),
            std::make_move_iterator(&tmp_array[size]),
            array);
    }
}


int main() {

	size_t len;
	std::cin >> len;
	int* arr = new int[len];

	for (size_t i = 0; i < len; i++)
		std::cin >> arr[i];

    sort(arr, len);

	for (size_t i = 0; i < len; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	return 0;
}