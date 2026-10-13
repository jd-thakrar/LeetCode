#include <stdio.h>
#include <conio.h>

int main()
{
    int n, m;
    printf("Enter the no. of elemnet: ");
    scanf("%d", &n);

    printf("Enter the amount: ");
    scanf("%d", &m);

    int arr[n];

    printf("Enter the elemnets: ");

    for (int i = 0; i < n; i++)
    {
        printf("Arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int dp[n][m + 1];
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 0;
            }
            else if (i == 0)
            {
                if (j % arr[i] == 0)
                {
                    dp[i][j] = j / arr[i];
                }
                else
                {
                    dp[i][j] = 0; 
                }
            }

            else if (arr[i] > j)
            {
            
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                int exclude = dp[i - 1][j];
                int include = 1 + dp[i][j - arr[i]];
                
                dp[i][j] = (exclude < include) ? exclude : include;
            }
        }
    }

    printf("Answer: %d", dp[n-1][m]);
    return 0;
}