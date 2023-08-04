// Project: Parallel Merge Sort (using Threads)
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 100

// Function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform merge sort on a subarray using threads
void* mergeSortThreaded(void* args) {
    int* arr = (int*)args;
    int left = 0;
    int right = arr[0] - 1;

    if (left < right) {
        int mid = left + (right - left) / 2;

        pthread_t tid1, tid2;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

        int args1[] = {mid - left + 1};
        int args2[] = {right - mid};

        // Create threads for the left and right subarrays
        pthread_create(&tid1, &attr, mergeSortThreaded, (void*)args1);
        pthread_create(&tid2, &attr, mergeSortThreaded, (void*)args2);

        // Wait for both threads to finish
        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);

        // Merge the sorted subarrays
        merge(arr + 1, left, mid, right);
    }

    pthread_exit(NULL);
}

// Function to perform parallel merge sort
void parallelMergeSort(int arr[], int size) {
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // Start the merge sort process with the whole array
    int args[] = {size};
    pthread_create(&tid, &attr, mergeSortThreaded, (void*)args);

    // Wait for the sorting to finish
    pthread_join(tid, NULL);
}

int main() {
    int arr[MAX_SIZE], size;

    printf("Welcome to Parallel Merge Sort!\n");

    printf("Enter the number of elements in the array (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    parallelMergeSort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
