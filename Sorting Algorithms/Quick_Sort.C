#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    
    int smallerThanPivotCount = 0;
    for(int i = start + 1; i <= end; i++)
        if(arr[i] <= pivot)
            smallerThanPivotCount++;

    // Placing pivot to right position
    int pivotIndex = start + smallerThanPivotCount;
    swap(&arr[start], &arr[pivotIndex]);

    //Sorting left and right parts of pivot
    while(start < pivotIndex && end > pivotIndex) {
        while (arr[start] < pivot)
            start++;
    
        while (arr[end] > pivot) 
            end--;
    
        if(start < pivotIndex && end > pivotIndex)
            swap(&arr[start++], &arr[end--]);
    }
    
    return pivotIndex;
}

void quickSort(int arr[], int start, int end) {
    if(start >= end)
        return ;

    // Place pivot in correct position
    int pivotIndex= partition(arr, start, end);

    //Sorting left-part
    quickSort(arr, start, pivotIndex-1);
    //Sorting right-part
    quickSort(arr, pivotIndex+1, end);
}

void printarr(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printarr(arr, n);

    return 0;
}