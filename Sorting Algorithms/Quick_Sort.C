#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int l, int h) {
    int pivot = a[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    i++;
    swap(&a[i], &a[h]);
    return (i);
}

void quickSort(int a[], int l, int h) {
    if (l < h) {
        int pi = partition(a, l, h);

        quickSort(a, l, pi - 1);
        quickSort(a, pi + 1, h);
    }
}

void printarr(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    quickSort(a, 0, n-1);
    printf("Sorted array: \n");
    printarr(a, n);
    
    return 0;
}