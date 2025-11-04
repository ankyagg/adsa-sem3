#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using Dynamic Programming
int knapsack_dp(int W, int weights[], int values[], int n) {
    // T[i][w] will store the maximum value that can be obtained
    int T[n + 1][W + 1];
    int i, w;    //rows,columns

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {

            if (i == 0 || w == 0) {
                T[i][w] = 0;
            }

            else if (weights[i - 1] <= w) {
                T[i][w] = max(values[i - 1] + T[i - 1][w - weights[i - 1]], T[i - 1][w]);
            }
            else {
                T[i][w] = T[i - 1][w];
            }
        }
    }

    // The result is the maximum value in the last cell of the table
    return T[n][W];
}

// --- Main Driver Code ---
int main() {
    // Item 1: value=60, weight=10
    // Item 2: value=100, weight=20
    // Item 3: value=120, weight=30
    int values[] = {60, 100, 120,600};
    int weights[] = {10, 20, 30,45};

    // Knapsack capacity
    int W = 70;

    // Number of items
    int n = sizeof(values) / sizeof(values[0]);

    printf("0/1 Knapsack Problem using Dynamic Programming\n");
    printf("Items: {Value, Weight}\n");
    for(int i = 0; i < n; i++) {
        printf("  Item %d: {%d, %d}\n", i + 1, values[i], weights[i]);
    }
    printf("Knapsack Capacity (W): %d\n\n", W);

    int max_val = knapsack_dp(W, weights, values, n);

    printf("Maximum value that can be put in the knapsack: %d\n", max_val);

    return 0;
}
