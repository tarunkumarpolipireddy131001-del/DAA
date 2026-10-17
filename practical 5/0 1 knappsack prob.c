#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int W = 5;
    int wt[] = {2, 3, 4, 5};
    int val[] = {3, 4, 5, 6};
    int n = sizeof(wt) / sizeof(wt[0]);

    int dp[n + 1][W + 1];
  
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (wt[i - 1] <= j) {
                int pick = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                int not_pick = dp[i - 1][j];
                dp[i][j] = max(pick, not_pick);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("DP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    printf("\nMaximum Value: %d\n", dp[n][W]);

    return 0;
}
