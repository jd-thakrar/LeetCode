#include <stdio.h>

int factRecursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factRecursive(n - 1);
}

int main() {
    int n;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Factorial of negative numbers is not defined.\n");
        return 1;
    }
    
    int resRecursive = factRecursive(n);
    
    int resIterative = 1;
    for (int i = 1; i <= n; i++) {
        resIterative *= i; 
    }
    
    printf("\n--- Results ---\n");
    printf("Result using Recursion function: %d\n", resRecursive);
    printf("Result using Iteration loop:    %d\n", resIterative);
    
    return 0;
}
