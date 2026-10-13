#include <stdio.h>
#include <conio.h>

int main()
{
    int n, m;
    printf("Enter the no. of elemnet: ");
    scanf("%d", &n);

    printf("Enter the bag capacity: ");
    scanf("%d", &m);

    int p[n],w[n];

    printf("Enter the profits: ");

    for (int i = 0; i < n; i++)
    {
        printf("p[%d]: ", i);
        scanf("%d", &p[i]);
    }
    printf("Enter the weights: ");

    for (int i = 0; i < n; i++)
    {
        printf("w[%d]: ", i);
        scanf("%d", &w[i]);
    }

    int dp[n+1][m + 1];
    for (int i = 0; i < n+1 ; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (j == 0 || i == 0)
            {
                dp[i][j] = 0;
            }
            else if (j >= w[i-1])
            {
                int up = dp[i - 1][j];
                int cal = p[i-1] + dp[i-1][j - w[i-1]];
                dp[i][j] = (up > cal) ? up : cal;
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    printf("Answer: %d", dp[n][m]);
    return 0;
}