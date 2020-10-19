//
// Created by Jeroen
//

#ifndef SORT_CPP_QUICKSORT_H
#define SORT_CPP_QUICKSORT_H

#include <functional>
#include <array>
#include <cstdint>
#include "SortUtil.h"

class QuickSort {
public:
    template<class T, std::size_t length>
    static void sort(std::array<T, length> &array, const std::function<int(const T &a, const T &b)> &compare) {
        sort(array, 0, array.size() - 1, compare);
    }

    QuickSort() = delete;

    ~QuickSort() = delete;

private:
    template<class T, std::size_t length>
    static void sort(std::array<T, length> &array, std::int32_t low, std::int32_t high,
                     const std::function<int(const T &a, const T &b)> &compare) {
        if (high <= low) {
            return;
        }
        std::int32_t part = partition(array, low, high, compare);
        sort(array, low, part - 1, compare);
        sort(array, part + 1, high, compare);
    }

    template<class T, std::size_t length>
    static std::int32_t partition(std::array<T, length> &array, std::int32_t low, std::int32_t high,
                                  const std::function<int(const T &a, const T &b)> &compare) {
        std::int32_t i = low, j = high + 1;
        const T &pivot = array[low];
        while (true) {
            while (less(compare, array[++i], pivot)) {
                if (i == high) {
                    break;
                }
            }
            while (less(compare, pivot, array[--j])) {
                if (j == low) {
                    break;
                }
            }
            if (i >= j) {
                break;
            }
            SortUtil::exchange(array, i, j);
        }
        SortUtil::exchange(array, low, j);
        return j;
    }



    template<class T>
    static bool less(const std::function<int(const T &a, const T &b)> &compare, const T &a, const T &b) {
        return compare(a, b) > 0;
    }
};


#endif //SORT_CPP_QUICKSORT_H
