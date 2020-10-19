package com.jeroen.sort.sorting;

public class QuickSort {

    public static <T extends Comparable<T>> void sort(T[] list) {
        sort(list, 0, list.length - 1);
    }

    private static <T extends Comparable<T>> void sort(T[] list, int low, int high) {
        if (high <= low) {
            return;
        }
        int partition = partition(list, low, high);
        sort(list, low, partition - 1);
        sort(list, partition + 1, high);
    }

    private static <T extends Comparable<T>> int partition(T[] list, int low, int high) {
        int i = low, j = high + 1;
        T pivot = list[low];
        while (true) {
            while (less(list[++i], pivot)) {
                if (i == high) {
                    break;
                }
            }
            while (less(pivot, list[--j])) {
                if (j == low) {
                    break;
                }
            }
            if (i >= j) {
                break;
            }
            exchange(list, i, j);
        }
        exchange(list, low, j);
        return j;
    }

    private static <T> void exchange(T[] list, int fromIndex, int toIndex) {
        T temp = list[fromIndex];
        list[fromIndex] = list[toIndex];
        list[toIndex] = temp;
    }

    private static <T extends Comparable<T>> boolean less(T a, T b) {
        return a.compareTo(b) < 0;
    }

}
