#include <stdio.h>

typedef struct {
    int weight;
    int profit;
    float ratio;
} Item;

void sort(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

float fractionalKnapsack(int capacity, Item items[], int n) {
    for (int i = 0; i < n; i++)
        items[i].ratio = (float)items[i].profit / items[i].weight;

    sort(items, n);

    int curWeight = 0;
    float finalProfit = 0.0;

    for (int i = 0; i < n; i++) {
        if (curWeight + items[i].weight <= capacity) {
            curWeight += items[i].weight;
            finalProfit += items[i].profit;
        } else {
            int remain = capacity - curWeight;
            finalProfit += items[i].profit * ((float) remain / items[i].weight);
            break;
        }
    }

    return finalProfit;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter weight and profit for item %d: ", i+1);
        scanf("%d%d", &items[i].weight, &items[i].profit);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Maximum profit: %f\n", fractionalKnapsack(capacity, items, n));
    return 0;
}