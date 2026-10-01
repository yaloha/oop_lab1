#include <iostream>
#include <limits>
#include "array_ops.h"

void print_menu() {
    std::cout << "========================\n"
              << "1. create an array\t\t2. print the array\n"
              << "3. insert an element\t\t4. delete an element\n"
              << "5. change arrays size\t\t6. count elements falling into specified range\n"
              << "0. exit the program\n"
              << "========================\n";
}

int get_safe_int(const char* text) {
    int value;
    while (true) {
        std::cout << text;
        if (std::cin >> value) {
            return value;
        }
        std::cout << "please input an integer. cmon. you can do it.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::size_t get_safe_size_t(const char* text) {
    long long value;
    while (true) {
        std::cout << text;
        if (std::cin >> value && value >= 0) {
            return static_cast<std::size_t>(value);
        }
        std::cout << "duuuuude its like arrays size yk please for the love of god input a positive integer\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main(){
    int* arr = nullptr;
    std::size_t size = 0;
    bool bleh = true;

    while (bleh) {
        print_menu();
        int choice = get_safe_int("please choose a menu section:");

        switch (choice) {
            case 1: {
                if (arr != nullptr) {
                    int del = get_safe_int("r u sure you want to overwrite the old array? 1 if yes, any other number if no:");
                    if (del == 1) {
                        arr_utils::array_delete(arr);
                        size = 0;
                        std::cout << "old array was NULLIFIED. ERADICATED. IT IS NO MORE.\n";
                    }else{
                        std::cout << "gotcha. well, i won't overwrite it. don't choose this option again.\n";
                        break;
                    }
                }
                size = get_safe_size_t("please enter the new arrays size:");
                arr = arr_utils::array_create(size);

                std::cout << "the array was bestowed upon you. treat it with care and fill it with integers residing in (0...1023) range:\n";
                for (std::size_t i = 0; i < size; ++i) {
                    std::string text = "the element [" + std::to_string(i) + "]:";
                    arr[i] = get_safe_int(text.c_str());
                }
                break;
            }
            case 2: {
                std::cout << "gaze upon your beautiful array:";
                arr_utils::array_print(arr, size);
                break;
            }
            case 3: {
                std::size_t pos = get_safe_size_t("enter the position to perform the magical INSERTION:");
                if (pos > size) {
                    std::cout << "oopsie position is like over the size of the array... yeah please reconsider\n";
                } else {
                    int value = get_safe_int("enter the value of the inserted element:");
                    arr_utils::array_insert(arr, size, pos, value);
                    std::cout << "the magical INSETION was perofrmed. be amazed.\n";
                }
                break;
            }
            case 4: {
                if (size == 0) {
                    std::cout << "your array is quite poor and has no elements... please donate some before trying to rob it even of them\n";
                    break;
                }
                std::size_t pos = get_safe_size_t("enter the position of the thingy you want to remove:");
                if (pos >= size) {
                    std::cout << "error: position > size. please reconsider.\n";
                } else {
                    arr_utils::array_remove(arr, size, pos);
                    std::cout << "successful ERADICATION. i hope you are happy.\n";
                }
                break;
            }
            case 5: {
                std::size_t new_size = get_safe_size_t("enter the new size you want to stretch or shrink your array to. your wish is gonna be granted!");
                arr_utils::array_resize(arr, size, new_size);
                size = new_size;
                std::cout << "it was stretched/shrank! yay!\n";
                break;
            }
            case 6: {
                int lo = get_safe_int("enter the lower range limit:");
                int hi = get_safe_int("enter the upper range limit:");

                std::size_t count = arr_utils::array_range_count(arr, size, lo, hi);
                std::cout << "your range [" << lo << ", " << hi << "] has... ta-da-da... !!" << count << "!! ...that many elements!" << '\n';
                break;
            }
            case 0: {
                bleh = false;
                break;
            }
            default: {
                std::cout << "please, please look at the menu again. do you see such a number? i sure do not. try again.\n";
                break;
            }
        }
    }

    arr_utils::array_delete(arr);
    std::cout << "its finally over... the memory is free. i also am finally free... bye...\n";
    return 0;
}