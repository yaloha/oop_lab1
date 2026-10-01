#include <cstddef>
#include <iostream>

namespace arr_utils {

    int *array_create(std::size_t size) {
        if (size == 0){
            return nullptr;
        }
        int *arr = new int[size]{};
        return arr;
    }

    void array_delete(int *&arr) {
        delete[] arr;
        arr = nullptr;
    }

    void array_resize(int *&arr, std::size_t &size, std::size_t new_size) {
        int *res_arr = new int[new_size]{};
        std::size_t to_copy = (size < new_size) ? size : new_size;
        for (std::size_t i = 0; i < to_copy; ++i) {
            res_arr[i] = arr[i];
        }
        delete[] arr;
        size = to_copy;
        arr = res_arr;
    }

    void array_insert(int *&arr, std::size_t &size, std::size_t pos, int value) {
        if (pos > size) {
            pos = size;
        }
        int *data = new int[size + 1]{};
        for (std::size_t i = 0; i < pos; ++i) {
            data[i] = arr[i];
        }
        data[pos] = value;
        for (std::size_t i = pos; i < size; ++i) {
            data[i + 1] = arr[i];
        }
        delete[] arr;
        ++size;
        arr = data;
    }

    void array_remove(int *&arr, std::size_t &size, std::size_t pos){
        if (size == 0 || pos >= size) {
            return;
        }
        int* data = new int[size - 1]{};
        for (std::size_t i = 0; i < pos; ++i) {
            data[i] = arr[i];
        }
        for (std::size_t i = pos + 1; i < size; ++i) {
            data[i - 1] = arr[i];
        }
        delete[] arr;
        --size;
        arr = data;
    }

    void array_print(const int *arr, std::size_t size){
        if (arr == nullptr || size == 0) {
            std::cout << "[]\n";
            return;
        }

        std::cout << "[";
        for (std::size_t i = 0; i < size; ++i) {
            std::cout << arr[i];
            if (i + 1 < size) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }

    std::size_t array_range_count(const int* arr, std::size_t size, int lo = 0, int hi = 1024){
        if (arr == nullptr || size == 0 || lo > hi)
            return 0;

        const int MAX_SIZE = 1024;
        int* table = array_create(MAX_SIZE);
        for (std::size_t i = 0; i < size; ++i) {
            int current_value = arr[i];
            if (current_value >= 0 && current_value < MAX_SIZE) {
                ++table[current_value];
            }
        }

        if (lo < 0) lo = 0;
        if (hi >= MAX_SIZE) hi = MAX_SIZE - 1;

        std::size_t sum = 0;
        for (int v = lo; v <= hi; ++v) {
            sum += table[v];
        }

        return sum;
    }

}