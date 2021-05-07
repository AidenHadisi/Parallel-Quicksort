#include <iostream>
#include <omp.h>
#include <chrono>


/**
* Sorts a sub array in each process
* @param arr a subarray passed from master process
**/
void swap(int* a, int* b);
int find_min_exp(int base, int target);
void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void quicksort_not_parallel(int arr[], int low, int high);