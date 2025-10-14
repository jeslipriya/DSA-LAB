#include <stdio.h>

void sortActivities(int n, int start[], int finish[]) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (finish[i] > finish[j]) {
                temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;

                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }
}

void activitySelection(int n, int start[], int finish[]) {
    int i, last = 0;

    printf("\nSelected activities (0-based index):\n");
    printf("%d ", 0);

    for (i = 1; i < n; i++) {
        if (start[i] >= finish[last]) {
            printf("%d ", i);
            last = i;
        }
    }
}

int main() {
    int n, i, start[50], finish[50];

    printf("Enter number of activities: ");
    scanf("%d", &n);

    printf("Enter start times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &start[i]);
    }

    printf("Enter finish times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &finish[i]);
    }

    sortActivities(n, start, finish);
    activitySelection(n, start, finish);

    return 0;
}



OUTPUT:

Enter number of activities: 4
Enter start times:
1 3 0 5
Enter finish times:
2 4 6 7

Selected activities (0-based index):
0 1 3 