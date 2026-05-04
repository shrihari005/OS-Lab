#include <stdio.h>
#define MAX 10

typedef struct {
    int id, execution, period, deadline;
    int remaining, next_release, abs_deadline;
} Task;

int main() {
    int n, time;
    Task t[MAX];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        t[i].id = i + 1;
        printf("\nTask %d Execution Time: ", i + 1);
        scanf("%d", &t[i].execution);
        printf("Task %d Period: ", i + 1);
        scanf("%d", &t[i].period);

        t[i].deadline = t[i].period;
        t[i].remaining = 0;
        t[i].next_release = 0;
    }

    printf("\nEnter simulation time: ");
    scanf("%d", &time);

    printf("\n--- Earliest Deadline First ---\n");

    for (int tme = 0; tme < time; tme++) {


        for (int i = 0; i < n; i++) {
            if (tme == t[i].next_release) {
                t[i].remaining = t[i].execution;
                t[i].abs_deadline = tme + t[i].deadline;
                t[i].next_release += t[i].period;
            }
        }

        int selected = -1;


        for (int i = 0; i < n; i++) {
            if (t[i].remaining > 0) {
                if (selected == -1 || t[i].abs_deadline < t[selected].abs_deadline) {
                    selected = i;
                }
            }
        }

        if (selected != -1) {
            printf("Time %d: Task %d\n", tme, t[selected].id);
            t[selected].remaining--;
        } else {
            printf("Time %d: Idle\n", tme);
        }
    }

    return 0;
}
