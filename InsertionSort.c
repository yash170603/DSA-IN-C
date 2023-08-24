// Start with the second element of the array. Assume the first element is sorted.
// Iterate over the unsorted portion of the array.
// Compare the current element with the elements in the sorted portion.
// Move the larger elements to the right until the correct position for the current element is found.
// Insert the current element in its correct position within the sorted portion.
// Repeat steps 2-5 until the entire array is sorted.


#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int currentElement = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > currentElement) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = currentElement;
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    insertionSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
