class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int a = n, armstrong = 0;
        while(a!=0){
            int digit = a%10;
            armstrong += digit*digit*digit;
            a/=10;
        }
        if(armstrong == n){
            return true;
        }else{
            return false;
        }
    }
};