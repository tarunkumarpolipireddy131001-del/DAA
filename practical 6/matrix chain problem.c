#include <stdio.h>
int main()
{
    int n, i, j, k;
    int a[10], dp[10][10];
    int cost, min;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter %d dimensions: ", n + 1);
    for(i = 0; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
  
    for(i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    for(i = n - 1; i >= 1; i--)
    {
        for(j = i + 1; j <= n; j++)
        {
            min = 999999;

            for(k = i; k < j; k++)
            {
                cost = dp[i][k] + dp[k + 1][j]
                     + a[i - 1] * a[k] * a[j];

                if(cost < min)
                {
                    min = cost;
                }
            }

            dp[i][j] = min;
        }
    }

    printf("Minimum number of multiplications = %d", dp[1][n]);

    return 0;
}
