#include <stdio.h>

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
} Process;

void roundRobin(Process p[], int n, int quantum) {
    int time = 0, TAT = 0, WT = 0;
    int chartSize = 0;

    // Calculate the size of the Gantt chart
    for (int i = 0; i < n; i++) {
        chartSize += (p[i].burst_time / quantum);
    }

    // Arrays to store the process IDs and time stamps for the Gantt chart
    int chartProcess[chartSize];
    int chartTime[chartSize + 1];

    chartTime[0] = 0;
    int chartIndex = 0;

    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (p[i].remaining_time > 0) {
                done = 0;
                if (p[i].remaining_time > quantum) {
                    time += quantum;
                    p[i].remaining_time -= quantum;
                } else {
                    time += p[i].remaining_time;
                    TAT += time;
                    WT += time - p[i].burst_time;
                    p[i].remaining_time = 0;
                }
                chartProcess[chartIndex] = p[i].id;
                chartTime[chartIndex + 1] = time;
                chartIndex++;
            }
        }
        if (done == 1)
            break;
    }

    printf("Gantt Chart:\n");
    printf("-");
    for (int i = 0; i < chartIndex; i++)
        printf("----------------");
    printf("\n");
    for (int i = 0; i < chartIndex; i++)
        printf("|\tP%d\t", chartProcess[i]);
    printf("|\n");
    printf("-");
    for (int i = 0; i < chartIndex; i++)
        printf("----------------");
    printf("\n");
    for (int i = 0; i <= chartIndex; i++)
        printf("%d\t\t", chartTime[i]);
    printf("\n");

    printf("Average turnaround time: %f\n", (float)TAT / n);
    printf("Average waiting time: %f\n", (float)WT / n);
}

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];
    printf("Enter burst time of processes: \n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
        p[i].id = i + 1;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    roundRobin(p, n, quantum);

    return 0;
}