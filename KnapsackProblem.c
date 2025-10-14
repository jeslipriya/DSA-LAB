#include <stdio.h>
#define MAX 20

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapSack(int n, int weight[], int value[], int W) {
    int i, w;
    int K[MAX][MAX];

    // Fill DP table
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i-1] <= w)
                K[i][w] = max(value[i-1] + K[i-1][w - weight[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    // Print maximum value
    printf("\nMaximum value in knapsack = %d\n", K[n][W]);

    // Trace which items to pick
    int res = K[n][W];
    w = W;
    printf("Selected items (index, weight, value):\n");
    for (i = n; i > 0 && res > 0; i--) {
        if (res != K[i-1][w]) {
            printf("Item %d: weight = %d, value = %d\n", i, weight[i-1], value[i-1]);
            res -= value[i-1];
            w -= weight[i-1];
        }
    }
}

int main() {
    int weight[MAX], value[MAX], n, W, i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items:\n");
    for (i = 0; i < n; i++) {
        printf("Weight of item %d: ", i+1);
        scanf("%d", &weight[i]);
    }

    printf("Enter value of items:\n");
    for (i = 0; i < n; i++) {
        printf("Value of item %d: ", i+1);
        scanf("%d", &value[i]);
    }

    printf("Enter maximum capacity of knapsack: ");
    scanf("%d", &W);

    knapSack(n, weight, value, W);

    return 0;
}


OUTPUT:

Enter number of items: 3
Enter weights of items:
Weight of item 1: 6
Weight of item 2: 3
Weight of item 3: 2
Enter value of items:
Value of item 1: 43
Value of item 2: 54
Value of item 3: 26
Enter maximum capacity of knapsack: 5

Maximum value in knapsack = 80
Selected items (index, weight, value):
Item 3: weight = 2, value = 26
Item 2: weight = 3, value = 54
