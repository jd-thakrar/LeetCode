#include <stdio.h>
#include <conio.h>
#include <limits.h>

int main()
{
    int n, dims_count;
    printf("Enter the no. of matrix: ");
    scanf("%d", &n);

    printf("Enter the elemnets: ");
    dims_count = n + 1;
    int arr[dims_count];
    for (int i = 0; i < dims_count; i++)
    {
        printf("Arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int cost_table[n][n], split_table[n][n];
    for (int i = 0; i < n; i++)
    {
        cost_table[i][i] = 0;
    }
    for (int l = 2; l <= n; l++)
    {

        for (int i = 0; i <= n - l ; i++)
        {
            int j = i + l - 1;
            cost_table[i][j] = INT_MAX;
            for (int k = i; k < j ; k++)
            {
                int q = cost_table[i][k] + cost_table[k+1][j] + arr[i] * arr[k+1] * arr[j+1];

                if(q<cost_table[i][j]){
                    cost_table[i][j] = q;
                    split_table[i][j] = k;
                }
            }
        }
    }

    printf("Answer: %d", cost_table[0][n-1]);
    return 0;
}