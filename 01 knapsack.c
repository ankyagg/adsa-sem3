#include <stdio.h>

// find max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// knapsack function (does everything)
int knapsack_dp(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1];

    // fill dp table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // print max value
    printf("\nMaximum value: %d\n", dp[n][W]);
    
    //dp table
    printf("\nDP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            printf("%3d ", dp[i][w]);
        }
        printf("\n");
    }

    // find which items were chosen
    int w = W;
    printf("Items chosen : ");
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {  // means item was included
            printf("%d ", i);
            w -= weights[i - 1];
        }
    }
    printf("\n");

    return dp[n][W];
}

// main function
int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int values[n], weights[n];

    for (int i = 0; i < n; i++) {
        printf("Enter value for item %d: ", i + 1);
        scanf("%d", &values[i]);
        printf("Enter weight for item %d: ", i + 1);
        scanf("%d", &weights[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    knapsack_dp(W, weights, values, n);

    return 0;
}
