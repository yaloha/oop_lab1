#include <gtest/gtest.h>
#include "../array_ops.h"

TEST(ArrMemory, CreateAndInitialize) {
std::size_t size = 5;
int* arr = arr_utils::array_create(size);
ASSERT_NE(arr, nullptr); 
for (std::size_t i = 0; i < size; ++i) {
EXPECT_EQ(arr[i], 0); 
}
arr_utils::array_delete(arr);
}


TEST(ArrMemory, ZeroSizeEQNull) {
int* arr = arr_utils::array_create(0);
EXPECT_EQ(arr, nullptr); 
}


TEST(ArrMemory, DeleteNullifPoint) {
int* arr = arr_utils::array_create(3);
arr_utils::array_delete(arr);


EXPECT_EQ(arr, nullptr);
}


TEST(ArrModifications, CorrectResize) {
std::size_t size = 3;
int* arr = arr_utils::array_create(size);
arr[0] = 1; arr[1] = 2; arr[2] = 3;

arr_utils::array_resize(arr, size, 5);

EXPECT_EQ(arr[0], 1);
EXPECT_EQ(arr[1], 2);
EXPECT_EQ(arr[2], 3);
EXPECT_EQ(arr[3], 0);  

arr_utils::array_delete(arr);
}

TEST(ArrModifications, CorrectDownsize) {
    std::size_t size = 5;
    int* arr = arr_utils::array_create(size);
    arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 4; arr[4] = 5;

    arr_utils::array_resize(arr, size, 2);

    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(size, 2);

    arr_utils::array_delete(arr);
}


TEST(ArrModifications, CorrectInsert) {
std::size_t size = 4;
int* arr = arr_utils::array_create(size);
arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 4;


arr_utils::array_insert(arr, size, 2, 505);

EXPECT_EQ(size, 5);       
EXPECT_EQ(arr[2], 505);
EXPECT_EQ(arr[3], 3);     
EXPECT_EQ(arr[4], 4);     

arr_utils::array_delete(arr);
}


TEST(ArrModifications, InsOutOfBounds) {
std::size_t size = 2;
int* arr = arr_utils::array_create(size);
arr[0] = 5; arr[1] = 10;

arr_utils::array_insert(arr, size, 10, 505);

EXPECT_EQ(size, 3);
EXPECT_EQ(arr[0], 5);

arr_utils::array_delete(arr);
}


TEST(ArrModifications, CorrectRemove) {
std::size_t size = 3;
int* arr = arr_utils::array_create(size);
arr[0] = 100; arr[1] = 200; arr[2] = 300;

arr_utils::array_remove(arr, size, 1); 

EXPECT_EQ(size, 2);
EXPECT_EQ(arr[0], 100);
EXPECT_EQ(arr[1], 300); 

arr_utils::array_delete(arr);
}

TEST(ArrFuncs, CorrectRange) {
std::size_t size = 7;
int* arr = arr_utils::array_create(size);

arr[0] = 5;
arr[1] = 55;
arr[2] = 500;
arr[3] = 5;
arr[4] = 1023;
arr[5] = 0;
arr[6] = 999;

std::size_t res = arr_utils::array_range_count(arr, size, 5, 500);
EXPECT_EQ(res, 4);

arr_utils::array_delete(arr);
}


TEST(ArrayFuncs, RangeExceptions) {
std::size_t size = 3;
int* arr = arr_utils::array_create(size);
arr[0] = 10; arr[1] = 20; arr[2] = 30;

EXPECT_EQ(arr_utils::array_range_count(arr, size, 100, 10), 0);
EXPECT_EQ(arr_utils::array_range_count(nullptr, 0, 0, 1000), 0);

arr_utils::array_delete(arr);
}