#include <stdio.h>

typedef struct {
    int no;
    int weight;
    int profit;
    float ratio;
} Item;

void sort(Item items[], int n) {
    for(int i = 0; i < n; i++) {
        Item key = items[i];
        int j = i - 1;
        while (j >= 0 && items[j].ratio < key.ratio) {
            items[j+1] = items[j];
            j--;
        }
        items[j+1] = key;
    }
}

void chart(Item items[], int n) {
    printf("\n\nSorted Chart:\nItem\tWeight\tProfit\tPi/Wi\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%f\n", items[i].no, items[i].weight, items[i].profit, items[i].ratio);
}

float fractionalKnapsack(int capacity, Item items[], int n) {
    for (int i = 0; i < n; i++)
        items[i].ratio = (float)items[i].profit / items[i].weight;

    sort(items, n);

    chart(items, n);

    int curWeight = 0;
    float finalProfit = 0.0;

    for (int i = 0; i < n; i++) {
        if (curWeight + items[i].weight <= capacity) {
            curWeight += items[i].weight;
            finalProfit += items[i].profit;
        } else {
            finalProfit += items[i].profit * ((float) (capacity - curWeight) / items[i].weight);
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
        items[i].no = i+1;
    }
    
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("\nMaximum profit: %f, for the given Capacity: %d", fractionalKnapsack(capacity, items, n), capacity);
    return 0;
}