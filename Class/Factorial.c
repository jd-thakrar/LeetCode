#include<stdio.h>
#include<conio.h>

// int main(){
//     int n = 5,ans=1;
//        if(n == 0 || n == 1)
//             return 1;
//      for(int i = 1; i<=n ; i++){
//         ans *= i;
//      }
//      printf("%d", ans);
//      return ans;
// }

int fib(int n){
    if(n == 0 || n==1){
        return 1;
    }
    return n * fib(n-1);
}
int main(){
    printf("%d",fib(0));
    return 0;
}