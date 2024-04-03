#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
typedef struct {
    int id;
    int burst_time;
    int remaining_time;
} Process;

void ins(int x) {
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->next = NULL;
    if (head == NULL)
        head = ptr;
    else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
}

void gantt_chart() {
    struct node *ptr;
    ptr = head;
    while (ptr != NULL) {
        printf("%d\t\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void roundRobin(int temp, Process p[], int n, int quantum) {
    int i, time = 0, TAT = 0, WT = 0;
    ins(time);
    temp /= 2;

    for (i = 0; i < 18 * temp; i++)
        printf("-");
    printf("\n|");

    while (1) {
        int done = 1;

        for (i = 0; i < n; i++) {
            if (p[i].remaining_time > 0) {
                done = 0;
                if (p[i].remaining_time > quantum) {
                    printf("\tP%d\t|", p[i].id);
                    time += quantum;
                    p[i].remaining_time -= quantum;
                    ins(time);
                } else {
                    printf("\tP%d\t|", p[i].id);
                    time = time + p[i].remaining_time;
                    TAT += time;
                    WT += time - p[i].burst_time;
                    p[i].remaining_time = 0;
                    ins(time);
                }
            }
        }
        if (done == 1)
            break;
    }

    printf("\n");
    for (i = 0; i < 17 * temp; i++)
        printf("-");
    printf("\n");

    gantt_chart();

    printf("\nAverage turnaround time: %d\n", TAT / n);
    printf("Average waiting time: %d\n", WT / n);
}

int main() {
    int n, i, quantum, temp = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];
    printf("Enter burst time of processes: \n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        temp += p[i].burst_time;
        p[i].remaining_time = p[i].burst_time;
        p[i].id = i + 1;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    roundRobin(temp, p, n, quantum);

    return 0;
}