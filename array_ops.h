#pragma once
#include <cstddef>


namespace arr_utils {

    int *array_create(std::size_t size);

    void array_delete(int *&arr);

    void array_resize(int *&arr, std::size_t &size, std::size_t new_size);

    void array_insert(int *&arr, std::size_t &size, std::size_t pos, int value);

    void array_remove(int *&arr, std::size_t &size, std::size_t pos);

    void array_print(const int *arr, std::size_t size);

    std::size_t array_range_count(const int* arr, std::size_t size, int lo = 0, int hi = 1024);

}