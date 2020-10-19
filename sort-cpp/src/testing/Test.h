//
// Created by Jeroen
//

#ifndef SORT_CPP_TEST_H
#define SORT_CPP_TEST_H

#include <iostream>
#include <functional>
#include <array>
#include <algorithm>
#include <random>
#include <iterator>
#include <cstdio>
#include <thread>
#include <chrono>
#include <fstream>

#include "../sorting/SortUtil.h"
#include "Stopwatch.h"

class Test {
public:

    template<class T>
    using CompareFunction = std::function<int(const T &a, const T &b)>;

    template<class T, std::size_t size>
    using SortFunction = std::function<void(std::array<T, size> &, const CompareFunction<T> &)>;

    template<std::size_t arrayLength>
    static void test(int iterations, const CompareFunction<int> &compare,
                     const SortFunction<int, arrayLength> &sortingAlg, std::ofstream &output) {
        std::random_device rd;
        std::mt19937_64 rng(rd());

        std::cout << "Starting sort test with array length " << arrayLength << " and " << iterations
                  << " number of iterations" << std::endl;

        Stopwatch stopwatch;

        std::array<int, arrayLength> array;
        fillArray(array);
        for (int iteration = 0; iteration < iterations; iteration++) {
            std::shuffle(std::begin(array), std::end(array), rng);
            stopwatch.start();
            sortingAlg(array, compare);
            stopwatch.stop();
            output << stopwatch.getDifference() << std::endl;
            if (!SortUtil::isSorted(array, compare)) {
                std::cerr << "Sorting algorithm did not produce a sorted array!" << std::endl;
                exit(3);
            }
            std::cout << "Length: " << arrayLength << ", iteration: " << iteration + 1 << ", "
                      << std::fixed << (((iteration + 1) * 1.0) / iterations * 100.0) << "%\r" << std::flush;
            // Give the os time to switch between CPU cores if it is needed.
            std::this_thread::sleep_for(std::chrono::microseconds(1));
        }
        std::cout << "Length: " << arrayLength << ", iteration: " << iterations << ", " << std::fixed << 100.0 << "%"
                  << std::endl;
    }

    Test() = delete;

    ~Test() = delete;

private:

    template<std::size_t arrayLength>
    static void fillArray(std::array<int, arrayLength> &array) {
        for (std::size_t i = 0; i < array.size(); i++) {
            array[i] = i + 1;
        }
    }

};

#endif //SORT_CPP_TEST_H
