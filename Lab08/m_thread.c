// Importing required libraries
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Setting maximum size of the array
#define MAX_SIZE 100000

// Global variables
int arr[MAX_SIZE]; // array to be sorted
int n, thread_count; // n: size of the array, thread_count: number of threads

// Struct to represent range of array
typedef struct {
int low;
int high;
} range;

// Function to merge two sorted subarrays
void merge(int low, int mid, int high) {
// Dynamically allocating memory for temporary arrays
int* left_arr = (int*) malloc((mid - low + 1) * sizeof(int));
int* right_arr = (int*) malloc((high - mid) * sizeof(int));

  int i, j, k;

// Copying values to temporary arrays
for (i = 0; i < mid - low + 1; i++) {
    left_arr[i] = arr[low + i];
}

for (j = 0; j < high - mid; j++) {
    right_arr[j] = arr[mid + 1 + j];
}

// Merging two subarrays
i = 0;
j = 0;
k = low;

while (i < mid - low + 1 && j < high - mid) {
    if (left_arr[i] <= right_arr[j]) {
        arr[k] = left_arr[i];
        i++;
    } else {
        arr[k] = right_arr[j];
        j++;
    }
    k++;
}

// Copying remaining elements to merged array
while (i < mid - low + 1) {
    arr[k] = left_arr[i];
    i++;
    k++;
}

while (j < high - mid) {
    arr[k] = right_arr[j];
    j++;
    k++;
}

// Freeing dynamically allocated memory
free(left_arr);
free(right_arr);
// Function to sort subarrays recursively
void* merge_sort(void* r) {
// Converting void pointer to range pointer
range* p = (range*) r;
    // Getting low and high indexes of subarray
int low = p->low;
int high = p->high;

// Checking if subarray has more than 1 element
if (low < high) {
    int mid = (low + high) / 2;

    // Checking if more than 1 thread can be used
    if (thread_count > 1) {
        thread_count -= 2;

        // Creating two threads for two subarrays
        pthread_t left_tid;
        pthread_t right_tid;

        range left_range = { low, mid };
        range right_range = { mid + 1, high };

        pthread_create(&left_tid, NULL, merge_sort, &left_range);
        pthread_create(&right_tid, NULL, merge_sort, &right_range);

        // Waiting for threads to finish
        pthread_join(left_tid, NULL);
        pthread_join(right_tid, NULL);

        thread_count += 2;
    } else {
        // Sorting subarrays recursively
        merge_sort(&((range){ low, mid }));
        merge_sort(&((range){ mid + 1, high }));
    }

    // Merging two sorted subarrays
    merge(low, mid, high);
}

return NULL;
