//
// Created by Jeroen
//

#ifndef SORT_CPP_SORTUTIL_H
#define SORT_CPP_SORTUTIL_H

#include <iostream>
#include <functional>
#include <array>

namespace SortUtil {
    template<class T, std::size_t size>
    bool isSorted(std::array<T, size> array, const std::function<int(const T &a, const T &b)> &compare) {
        if (array.size() <= 1) {
            return true;
        }
        for (int i = 1; i < array.size(); i++) {
            if (compare(array[i - 1], array[i]) < 0) {
                return false;
            }
        }
        return true;
    }

    template<class T, std::size_t size>
    void printArray(std::array<T, size> array) {
        std::cout << "[";
        for (int i = 0; i < array.size(); i++) {
            if (i > 0) {
                std::cout << ", ";
            }
            std::cout << array[i];
        }
        std::cout << "]" << std::endl;
    }

//    template<class T, std::size_t arrayLength>
//    void shuffle(std::array<T, arrayLength> &array) {
//        for (std::size_t i = array.size(); i > 1; --i) {
//            exchange(array, i - 1, )
//        }
//    }

    template<class T, std::size_t length>
    static void exchange(std::array<T, length> &array, int fromIndex, int toIndex) {
        T temp = std::move(array[fromIndex]);
        array[fromIndex] = array[toIndex];
        array[toIndex] = temp;
    }
}

#endif //SORT_CPP_SORTUTIL_H
