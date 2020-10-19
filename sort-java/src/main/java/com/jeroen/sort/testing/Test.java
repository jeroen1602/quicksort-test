package com.jeroen.sort.testing;

import com.jeroen.sort.sorting.SortInterface;
import com.jeroen.sort.sorting.SortUtil;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Test {

    public static void test(int arrayLength, int iterations, final SortInterface<Integer> sortingAlg,
                            final File outputFile) throws IOException {
        if (outputFile.exists()) {
            throw new RuntimeException("Output file already exists!");
        } else {
            outputFile.createNewFile();
        }
        FileWriter output = new FileWriter(outputFile, StandardCharsets.UTF_8, false);
        final Stopwatch stopwatch = new Stopwatch();
        System.out.printf("Starting sort test with array length %d and %d number of iterations\n", arrayLength, iterations);
        for (int iteration = 0; iteration < iterations; iteration++) {
            Integer[] array = createArray(arrayLength);
            stopwatch.start();
            sortingAlg.sort(array);
            stopwatch.stop();
            if (!SortUtil.isSorted(array)) {
                throw new RuntimeException("Sorting algorithm did not produce a sorted array!");
            }
            long difference = stopwatch.getDifference();
            output.write(String.format("%d\n", difference));
            System.out.printf("Length: %d, iteration: %d, %.2f%%\r", arrayLength, iteration + 1, (((iteration + 1) * 1.0) / iterations * 100.0));
        }
        System.out.printf("Length: %d, iteration: %d, %.2f%%\n", arrayLength, iterations, 100.0);
        output.flush();
        output.close();
    }

    private static Integer[] createArray(int length) {
        if (length <= 0) {
            System.err.println("Cannot create an array with a negative length");
            System.exit(3);
        }
        Integer[] array = new Integer[length];
        for (int i = 0; i < array.length; i++) {
            array[i] = i + 1;
        }
        shuffle(array);
        return array;
    }

    private static <T> void shuffle(T[] array) {
        List<T> list = Arrays.asList(array);
        Collections.shuffle(list);
        list.toArray(array);
    }

}
