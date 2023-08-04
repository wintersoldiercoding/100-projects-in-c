// Project: Binary Search Algorithm
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; // Key found at index mid
        } else if (arr[mid] < key) {
            low = mid + 1; // Key is in the right half of the array
        } else {
            high = mid - 1; // Key is in the left half of the array
        }
    }

    return -1; // Key not found in the array
}

int main() {
    int size, key;

    printf("Welcome to the Binary Search Algorithm!\n");

    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the sorted array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &key);

    int index = binarySearch(arr, size, key);

    if (index != -1) {
        printf("Element %d found at index %d.\n", key, index);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
