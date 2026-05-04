#include <stdio.h>

#define MAX 10

typedef struct {
    int id, execution, period, remaining, next_release;
} Task;

int main() {
    int n, time;
    Task t[MAX];

    int queue[MAX], front = 0, rear = 0;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        t[i].id = i + 1;
        printf("\nTask %d Execution Time: ", i + 1);
        scanf("%d", &t[i].execution);
        printf("Task %d Period: ", i + 1);
        scanf("%d", &t[i].period);

        t[i].remaining = 0;
        t[i].next_release = 0;
    }

    printf("\nEnter simulation time: ");
    scanf("%d", &time);

    printf("\n--- Proportional Scheduling (Round Robin) ---\n");

    for (int tme = 0; tme < time; tme++) {

        for (int i = 0; i < n; i++) {
            if (tme == t[i].next_release) {
                t[i].remaining = t[i].execution;
                t[i].next_release += t[i].period;
                queue[rear++] = i;
            }
        }

        if (front < rear) {
            int i = queue[front++];

            printf("Time %d: Task %d\n", tme, t[i].id);
            t[i].remaining--;

            if (t[i].remaining > 0) {
                queue[rear++] = i;
            }
        } else {
            printf("Time %d: Idle\n", tme);
        }
    }

    return 0;
}
