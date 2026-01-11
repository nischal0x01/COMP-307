#include <stdio.h>

int main() {
    int n, bt[10], rt[10], wt[10], tat[10];
    int time = 0, remain, smallest;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    remain = n;
    while(remain != 0) {
        smallest = -1;
        for(int i = 0; i < n; i++) {
            if(rt[i] > 0 && (smallest == -1 || rt[i] < rt[smallest]))
                smallest = i;
        }

        rt[smallest]--;
        time++;

        if(rt[smallest] == 0) {
            remain--;
            wt[smallest] = time - bt[smallest];
            tat[smallest] = time;
        }
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);

    return 0;
}
