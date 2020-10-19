package com.jeroen.sort;

import com.jeroen.sort.sorting.QuickSort;
import com.jeroen.sort.sorting.SortInterface;
import com.jeroen.sort.testing.Test;

import java.io.File;
import java.io.IOException;

public class Main {

    public static void main(String[] args) throws IOException {
        tests(new int[]{100, 1000, 10000, 100000, 1000000}, 1000, QuickSort::sort);
        tests(new int[]{20000, 40000, 80000, 160000}, 1000, QuickSort::sort);
    }

    private static void tests(int[] lengths, int iterations, final SortInterface<Integer> sortingAlg) {
        for (int i = 0; i < lengths.length; i++) {
            System.out.printf("Running test %d of %d (%.2f%%)\n", i + 1, lengths.length, ((i * 1.0) / lengths.length * 100.0));
            try {
                Test.test(lengths[i], iterations, sortingAlg, new File(String.format("./%d.csv", lengths[i])));
            } catch (final IOException ioException) {
                ioException.printStackTrace();
            } catch (final RuntimeException exception) {
                System.err.printf("File ./%d.csv already exists, skipping this test\n", lengths[i]);
            }

        }
    }

}
