class Solution {
public:
    long long sumAndMultiply(int n) {
      long long  x=0;
      long long sum = 0;
      long long mul = 1;
      while(n > 0){
          
          int last = n%10;
          n=n/10;
          
          if(last!=0){
              sum += last;
              x = x + (last*mul);
              mul *=10;
          }
      }
      return x*sum;
    }
};