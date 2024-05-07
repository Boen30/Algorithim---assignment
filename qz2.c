#include <stdio.h>
#include <stdlib.h>

// Function to reverse an array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to perform circular shift on a sorted array
void circular_shift(int arr[], int n, int k) {
    k = k % n; // To handle cases where k > n
    reverse(arr, 0, n - 1); // Reverse the entire array
    reverse(arr, 0, k - 1); // Reverse the first k elements
    reverse(arr, k, n - 1); // Reverse the remaining elements
}

// Function to print an array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {5, 15, 29, 35, 42};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 2;

    circular_shift(A, n, k);
    print_array(A, n);

    k = 4;
    circular_shift(A, n, k);
    print_array(A, n);

    return 0;
}
