#include <stdio.h>
#define MAX 10

int adj[MAX][MAX];
int visited[MAX];

void main() {
    int node, cost = 0, n;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the weights:");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("\n%d-%d: ", i, j);
            scanf("%d", &adj[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[0] = 1;
    int vertices = 0;

    while (vertices < n - 1) {
        int min = 999, u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && adj[i][j] && adj[i][j] < min) {
                        min = adj[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("\n%d - %d : %d", u, v, min);
            visited[v] = 1;
            cost += min;
            vertices++;
        }
    }

    printf("\nMin cost: %d", cost);
}
