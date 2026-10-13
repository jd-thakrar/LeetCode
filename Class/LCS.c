#include<conio.h>
#include<stdio.h>
#include<string.h>

int main(){
  char s1[100];
    char s2[100];

    printf("Enter string 1: ");
    scanf("%s", s1); // Simple input, no & needed for strings

    printf("Enter string 2: ");
    scanf("%s", s2);

    int n = strlen(s1);
    int m = strlen(s2);
    int dp[n+1][m+1];
    for(int i = 0 ; i<=n;i++){
        for(int j = 0; j<=m; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i-1][j-1]; 
            else {
                int up = dp[i - 1][j];
                int left = dp[i][j-1];
                dp[i][j] = up > left ? up : left;
            }
        }
    }
    printf("Answer: %d", dp[n][m]);
    return 0;
}