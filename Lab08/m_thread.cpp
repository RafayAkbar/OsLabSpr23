#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 1000
#define MAX_THREADS 16

int data[MAX_SIZE];
int sorted[MAX_SIZE];
int thread_count;
pthread_t threads[MAX_THREADS];

void merge(int start, int mid, int end) {
    int i, j, k;
    i = start;
    j = mid + 1;
    k = start;
    while (i <= mid && j <= end) {
        if (data[i] < data[j]) {
            sorted[k++] = data[i++];
        } else {
            sorted[k++] = data[j++];
        }
    }
    while (i <= mid) {
        sorted[k++] = data[i++];
    }
    while (j <= end) {
        sorted[k++] = data[j++];
    }
    for (i = start; i <= end; i++) {
        data[i] = sorted[i];
    }
}

void* merge_sort(void* arg) {
    int thread_num = *(int*)arg;
    int start = thread_num * (MAX_SIZE / thread_count);
    int end = (thread_num + 1) * (MAX_SIZE / thread_count) - 1;
    int mid = (start + end) / 2;
    if (start < end) {
        merge_sort(&thread_num);
        merge_sort(&thread_num);
        merge(start, mid, end);
    }
    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    int i;
    thread_count = 16;
    for (i = 0; i < MAX_SIZE; i++) {
        data[i] = rand() % MAX_SIZE;
    }
    for (i = 0; i < thread_count; i++) {
        pthread_create(&threads[i], NULL, merge_sort, &i);
    }
    for (i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
    merge(0, (MAX_SIZE - 1) / 2, MAX_SIZE - 1);
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}

