// сортировка слиянием
#include <iostream>
#include <iterator>
#include <memory>


void sort(int array[], std::size_t size) {
    if (size > 1) {
        std::size_t const left_size = size / 2;
        std::size_t const right_size = size - left_size;

        // дробление массива посредством рекурсивного вызова процедуры
        sort(&array[0], left_size);
        sort(&array[left_size], right_size);

        std::size_t left = 0, right = left_size, curr_id = 0;
        std::unique_ptr<int[]> tmp_array(new int[size]);

        // упорядоченная запись элементов двух раздробленных массивов в один
        while (left < left_size || right < size) {
            if (array[left] < array[right]) {
                tmp_array[curr_id++] = std::move(array[left]);
                left++;
            }
            else {
                tmp_array[curr_id++] = std::move(array[right]);
                right++;
            }

            if (left == left_size) {
                std::copy(std::make_move_iterator(&array[right]),
                    std::make_move_iterator(&array[size]),
                    &tmp_array[curr_id]);
                break;
            }
            if (right == size) {
                std::copy(std::make_move_iterator(&array[left]),
                    std::make_move_iterator(&array[left_size]),
                    &tmp_array[curr_id]);
                break;
            }
        }

        std::copy(std::make_move_iterator(tmp_array.get()),
            std::make_move_iterator(&tmp_array[size]),
            array); // копирование отсортированной части в исходный массив
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
