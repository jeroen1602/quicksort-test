
#include <iostream>
#include <array>
#include <filesystem>
#include <fstream>
#include <sstream>

#include "sorting/QuickSort.h"
#include "testing/Test.h"

template<std::size_t size>
void testWithQuickSort(int iterations, const Test::CompareFunction<int> &compare) {
    Test::SortFunction<int, size> sortAlg = [](std::array<int, size> &array,
                                               const Test::CompareFunction<int> &compare) -> void {
        QuickSort::sort(array, compare);
    };
    std::stringstream ss;
    ss << "./" << size << ".csv";
    std::filesystem::directory_entry filePath(ss.str());
    if (filePath.exists()) {
        std::cerr << "Output file " << filePath << " already exists. Skipping this test" << std::endl;
        return;
    }
    std::ofstream outputFile(filePath.path());
    Test::test<size>(iterations, compare, sortAlg, outputFile);
    outputFile.flush();
    outputFile.close();
}

int main() {
    Test::CompareFunction<int> compare = [](const int &a, const int &b) -> int {
        return b - a;
    };
    testWithQuickSort<100>(1000, compare);
    testWithQuickSort<1000>(1000, compare);
    testWithQuickSort<10000>(1000, compare);
    testWithQuickSort<20000>(1000, compare);
    testWithQuickSort<40000>(1000, compare);
    testWithQuickSort<80000>(1000, compare);
    testWithQuickSort<100000>(1000, compare);
    testWithQuickSort<160000>(1000, compare);
    testWithQuickSort<1000000>(1000, compare);

    return 0;
}


