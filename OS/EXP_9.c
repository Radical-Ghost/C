#include <stdio.h>

void print_table(int processSizes[], int allocation[], int n) {
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSizes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void firstFit(int blockSizes[], int m, int processSizes[], int n) {
    int allocation[n];

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
        for (int j = 0; j < m; j++) {
            if (blockSizes[j] >= processSizes[i]) {
                allocation[i] = j;
                blockSizes[j] -= processSizes[i];
                break;
            }
        }
    }

    print_table(processSizes, allocation, n);
}

void best_worst_Fit(int blockSizes[], int m, int processSizes[], int n,
                    int type) {
    int allocation[n];

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
        int index = -1;
        for (int j = 0; j < m; j++) {
            if (blockSizes[j] >= processSizes[i]) {
                if ((type == 1 &&
                         (index == -1 || blockSizes[index] > blockSizes[j]) ||
                     (type == 2 &&
                      (index == -1 || blockSizes[index] < blockSizes[j]))))
                    index = j;
            }
        }

        if (index != -1) {
            allocation[i] = index;
            blockSizes[index] -= processSizes[i];
        }
    }

    print_table(processSizes, allocation, n);
}

int main() {
    int m, n, choice = 0;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    int blockSizes[m];
    printf("Enter the sizes of the memory blocks: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSizes[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processSizes[n];
    printf("Enter the sizes of the processes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSizes[i]);
    }

    while (choice != 4) {
        printf("Choose the memory allocation strategy:\n1. First Fit\n2. Best "
               "Fit\n3. Worst Fit\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nFirst Fit:\n");
            firstFit(blockSizes, m, processSizes, n);
            break;
        case 2:
            printf("\nBest Fit:\n");
            best_worst_Fit(blockSizes, m, processSizes, n, 1);
            break;
        case 3:
            printf("\nWorst Fit:\n");
            best_worst_Fit(blockSizes, m, processSizes, n, 2);
            break;
        case 4:
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
