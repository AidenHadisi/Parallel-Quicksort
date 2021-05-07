#include "sort.h"

void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

int find_min_exp(int base, int target) {
    int i = 0;
    while (pow(base, i) < target) { i++; }
    return i;
}

int partition(int arr[], int low, int high) { //sort the partition
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++;
            swap(arr + i, arr + j);
        }
    }
    
    swap(arr + i + 1, arr + high);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    //TODO: Implement
    if (low < high)
    {
        int mid = partition(arr, low, high);

#pragma omp parallel 
        {
            quicksort(arr, low, mid - 1);
            quicksort(arr, mid + 1, high);
        }
    }
}

void quicksort_not_parallel(int arr[], int low, int high) {
    //TODO: Implement
    if (low < high)
    {
        int mid = partition(arr, low, high);
        quicksort_not_parallel(arr, low, mid - 1);
        quicksort_not_parallel(arr, mid + 1, high);
    }
}