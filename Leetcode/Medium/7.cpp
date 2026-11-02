class Solution {
public:
    int reverse(int x) {
       long long n = 0;
       while(x!=0){
        int digit = x%10;
        n = (n*10) + digit;
        x /= 10;
       } 

       if(n > INT_MAX || n < INT_MIN){
        return 0;
       }
       
       return int(n);
    }
};