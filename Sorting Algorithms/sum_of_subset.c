#include <stdio.h>

void sos(int arr[], int n, int data[], int index, int i, int sum) {
    int j;

    if (sum == 0) {
        for (j = 0; j < index; j++)
            printf("%d ", data[j]);
        printf("\n");
        return;
    }

    if (i >= n || sum < 0)
        return;

    data[index] = arr[i];
    sos(arr, n, data, index + 1, i + 1, sum - arr[i]);
    sos(arr, n, data, index, i + 1, sum);
}

int main() {
    int i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n], data[n], sum;
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the sum: ");
    scanf("%d", &sum);

    printf("The subsets are: \n");
    sos(arr, n, data, 0, 0, sum);

    return 0;
}