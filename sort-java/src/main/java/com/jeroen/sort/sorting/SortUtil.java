package com.jeroen.sort.sorting;

public class SortUtil {

    public static <T extends Comparable<T>> boolean isSorted(T[] array) {
        if (array.length <= 1) {
            return true;
        }
        for (int i = 1; i < array.length; i++) {
            if (array[i-1].compareTo(array[i]) > 0) {
                return false;
            }
        }
        return true;
    }

}
