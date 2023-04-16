#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 100000

int arr[MAX_SIZE];
int n, thread_count;

typedef struct {
    int low;
    int high;
} range;

void merge(int low, int mid, int high) {
    int* left_arr = (int*) malloc((mid - low + 1) * sizeof(int));
    int* right_arr = (int*) malloc((high - mid) * sizeof(int));

    int i, j, k;

    for (i = 0; i < mid - low + 1; i++) {
        left_arr[i] = arr[low + i];
    }

    for (j = 0; j < high - mid; j++) {
        right_arr[j] = arr[mid + 1 + j];
    }

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

    free(left_arr);
    free(right_arr);
}

void* merge_sort(void* r) {
    range* p = (range*) r;

    int low = p->low;
    int high = p->high;

    if (low < high) {
        int mid = (low + high) / 2;

        if (thread_count > 1) {
            thread_count -= 2;

            pthread_t left_tid;
            pthread_t right_tid;

            range left_range = { low, mid };
            range right_range = { mid + 1, high };

            pthread_create(&left_tid, NULL, merge_sort, &left_range);
            pthread_create(&right_tid, NULL, merge_sort, &right_range);

            pthread_join(left_tid, NULL);
            pthread_join(right_tid, NULL);

            thread_count += 2;
        } else {
            merge_sort(&((range){ low, mid }));
            merge_sort(&((range){ mid + 1, high }));
        }

        merge(low, mid, high);
    }

    return NULL;
}

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of threads to be used: ");
    scanf("%d", &thread_count);

    pthread_t tid;

    range r = { 0, n - 1 };
    pthread_create(&tid, NULL, merge_sort, &r);

    pthread_join(tid, NULL);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

