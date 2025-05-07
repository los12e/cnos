10.A):- FCFS
#include <stdio.h>
int main() {
    int pid[10], bt[10], wt[10], tat[10], n, twt = 0, ttat = 0, i;
    float awt, atat;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter burst times for %d processes:\n", n);
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    tat[0] = bt[0];
    for (i = 1; i < n; i++) {
        wt[i] = tat[i - 1];
        tat[i] = wt[i] + bt[i];
    }
    for (i = 0; i < n; i++) {
        twt += wt[i];
        ttat += tat[i];
    }
    printf("\nPID\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    awt = (float)twt / n;
    atat = (float)ttat / n;
    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", atat);
    return 0;
}
O/P:-
Enter number of processes: 3
Enter burst times for 3 processes:
Process 1: 1
Process 2: 2
Process 3: 3

PID	BT	WT	TAT
1	1	0	1
2	2	1	3
3	3	3	6

Average Waiting Time: 1.33
Average Turnaround Time: 3.33


10.B):- PRIORITY
#include <stdio.h>
int main() {
    int pid[10], bt[10], pr[10], wt[10], tat[10], n;
    int twt = 0, ttat = 0, i, j, temp;
    float awt, atat;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    printf("Enter process IDs:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pid[i]);
    }
    printf("Enter priorities (lower number = higher priority):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pr[i]);
    }
    // Sort processes by priority using simple bubble sort
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                // Swap priority
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                // Swap burst time
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                // Swap process ID
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }
    // Calculate Waiting Time and Turnaround Time
    wt[0] = 0;
    tat[0] = bt[0];
    for (i = 1; i < n; i++) {
        wt[i] = tat[i - 1];
        tat[i] = wt[i] + bt[i];
    }

    // Total WT and TAT
    for (i = 0; i < n; i++) {
        twt += wt[i];
        ttat += tat[i];
    }

    // Display the result
    printf("\nPID\tPriority\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t%d\t%d\n", pid[i], pr[i], bt[i], wt[i], tat[i]);
    }

    awt = (float)twt / n;
    atat = (float)ttat / n;

    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", atat);

    return 0;
}


O/P:-
Enter number of processes: 2
Enter burst times:
P1: 1
P2: 2
Enter process IDs:
3
3
Enter priorities (lower number = higher priority):
2
3
PID	Priority	BT	WT	TAT
3	2		1	0	1
3	3		2	1	3
Average Waiting Time: 0.50
Average Turnaround Time: 2.00
