#include <stdio.h>

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
} Process;

void Sort(Process p[], int n) {
    for (int i = 0; i < n; i++) {
        Process key = p[i];
        int j = i - 1;
        while (j >= 0 && p[j].arrival_time > key.arrival_time) {
            p[j + 1] = p[j];
            j--;
        }
        p[j + 1] = key;
    }
}

int main() {
    int n, i, t = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];
    int wt[n], tat[n], ft[n + 1];
    printf("Enter burst time and arrival time of processes: \n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &p[i].burst_time, &p[i].arrival_time);
        p[i].id = i + 1;
    }

    Sort(p, n);

    ft[0] = 0;
    for (i = 1; i <= n; i++) {
        ft[i] = ft[i - 1] + p[i - 1].burst_time;
        tat[i - 1] = ft[i] - p[i - 1].arrival_time;
        wt[i - 1] = tat[i - 1] - p[i - 1].burst_time;
    }

    // table
    printf("-");
    for (i = 0; i < n; i++)
        printf("----------------");
    printf("\n");
    for (i = 0; i < n; i++)
        printf("|\tP%d\t", p[i].id);
    printf("|\n");
    printf("-");
    for (i = 0; i < n; i++)
        printf("----------------");
    printf("\n");
    for (i = 0; i < n; i++)
        printf("%d\t\t", ft[i]);
    printf("%d\n", ft[n]);

    int avg_wt = 0, avg_tat = 0;
    for (i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("Average waiting time: %f\n", (float)avg_wt / n);
    printf("Average turn around time: %f\n", (float)avg_tat / n);

    return 0;
}
