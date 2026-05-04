#include <stdio.h>

void calculateScheduling(int n, int bt[], int at[], int quantum) {
    int wt[n], tat[n], rem_bt[n], ct[n];
    int total_wt = 0, total_tat = 0, t = 0, completed = 0;
    int visited[n];

    for (int i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
        visited[i] = 0;
    }

    while (completed < n) {
        int executed = 0;

        for (int i = 0; i < n; i++) {
            if (at[i] <= t && rem_bt[i] > 0) {
                executed = 1;

                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    ct[i] = t;
                    rem_bt[i] = 0;
                    completed++;
                }
            }
        }

        if (!executed) t++;
    }

    printf("\nQuantum: %d\n", quantum);
    printf("P | AT | BT | WT | TAT\n");

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d | %d | %d | %d | %d\n", i+1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("Avg WT: %.2f, Avg TAT: %.2f\n", (float)total_wt/n, (float)total_tat/n);
}

int main() {
    int n, q;
    printf("Enter number of processes: "); scanf("%d", &n);

    int bt[n], at[n];

    for (int i = 0; i < n; i++) {
        printf("Arrival Time P%d: ", i+1); scanf("%d", &at[i]);
        printf("Burst Time P%d: ", i+1); scanf("%d", &bt[i]);
    }

    printf("Enter Quantum: "); scanf("%d", &q);

    calculateScheduling(n, bt, at, q);

    return 0;
}
