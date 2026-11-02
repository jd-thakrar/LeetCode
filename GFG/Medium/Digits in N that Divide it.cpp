class Solution {
  public:
    int divisibleByDigits(string& s) {
       int rem[10] = {0};
       for(char ch : s){
           int d = ch - '0';
           
           for(int i = 1 ; i <= 9; i++){
               rem[i] = (rem[i] * 10 + d) % i;
           }
       }
       int sum = 0;
       for(char ch : s){
           int digit = ch -'0';
           if(digit !=0 && rem[digit]==0){
               sum++;
           }
       }
       return sum;
    }
};
//https://www.geeksforgeeks.org/problems/count-digits-in-given-number-n-which-divide-n3331/1