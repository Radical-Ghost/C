#include <stdio.h>

void merge(int a[], int left[], int right[], int ls, int rs){
    int i = 0, l = 0, r = 0;

    while(l < ls && r < rs) {
        if(left[l] < right[r])
            a[i++] = left[l++];
        else
            a[i++] = right[r++];
    }

    while(l < ls)
        a[i++] = left[l++];

    while(r < rs)
        a[i++] = right[r++];
}

void mergeSort(int a[], int n){
    if(n > 1){
        int i, mid = n/2;
        int left[mid], right[n-mid];

        for(i = 0; i < n; i++) {
            if(i < mid)
                left[i] = a[i];
            else
                right[i-mid] = a[i];
        }

        mergeSort(left, mid);
        mergeSort(right, n-mid);
        merge(a, left, right, mid, n-mid);
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
    
    mergeSort(a, n);
    printf("Sorted array: \n");
    printarr(a, n);
    
    return 0;
}