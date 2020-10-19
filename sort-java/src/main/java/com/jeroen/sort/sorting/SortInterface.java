package com.jeroen.sort.sorting;

public interface SortInterface<T extends Comparable<T>> {
    void  sort(T[] array);
}
