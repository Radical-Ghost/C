#include <stdio.h>

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int priority;
} Process;

void bubbleSort(Process p[], int n, int key) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if ((key == 1 && p[j].burst_time > p[j+1].burst_time) || 
                (key == 2 && p[j].arrival_time > p[j+1].arrival_time) ||
                (key == 1 && p[j].priority > p[j+1].priority)) {
                Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, i, t = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];
    int wt[n], tat[n], ft[n+1];
    printf("Enter burst time, access time and priority of processes: \n");
    for(i=0; i<n; i++){
        printf("P%d: ", i+1);
        scanf("%d %d %d", &p[i].burst_time, &p[i].arrival_time, &p[i].priority);
        p[i].id = i+1;
    }

    bubbleSort(p, n, 3);
    bubbleSort(p, n, 1);
    bubbleSort(p, n, 2);

    ft[0] = 0;
    for(i=1; i<=n; i++){
        ft[i] = ft[i-1] + p[i-1].burst_time;
        tat[i-1] = ft[i] - p[i-1].arrival_time;
        wt[i-1] = tat[i-1] - p[i-1].burst_time;
    }

    //table
    for(i=0; i<16*n+1; i++)
        printf("-");
    printf("\n");
    for(i=0; i<n; i++)
        printf("|\tP%d\t", p[i].id);
    printf("|\n");
    for(i=0; i<16*n+1; i++)
        printf("-");
    printf("\n");
    for(i=0; i<n; i++)
        printf("%d\t\t", ft[i]);
    printf("%d\n", ft[n]);

    int avg_wt=0, avg_tat=0;
    for(i=0; i<n; i++){
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("Average waiting time: %f\n", (float)avg_wt/n);
    printf("Average turn around time: %f\n", (float)avg_tat/n);

    return 0;
}