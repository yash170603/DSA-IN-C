Bubble Sort Algorithm:

// Start with the first element of the array.
// Compare the current element with the next element.
// If the current element is larger than the next element, swap them.
// Move to the next pair of elements and repeat steps 2-3 until the end of the array is reached.
// After the first pass, the largest element will have "bubbled up" to the last position.
// Repeat steps 1-5 for the remaining elements, excluding the last one in each pass.
// Continue this process until the entire array is sorted.



// procedure bubbleSort(arr: array of elements)
//     n = length(arr)
//     for i from 0 to n - 1
//         swapped = false
//         for j from 0 to n - i - 1
//             if arr[j] > arr[j+1]
//                 swap(arr[j], arr[j+1])
//                 swapped = true
//         if swapped = false
//             break
//     end for
// end procedure

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) {
            // If no two elements were swapped in the inner loop, the array is already sorted
            break;
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

