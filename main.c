#include <stdio.h>

// Function to print the index where the element can be inserted
int insertList(int num) {
    printf("Seems like element is not in the given array. You can insert it at index %d\n", num+1);
    return num+1;
}

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }

        // Check if we have reached the insertion point
        if (mid == right || mid == left) {
            insertList(mid);
        }
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element not found !!");
    }

    return 0;
}
