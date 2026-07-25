class Solution {
public:
    int maxProduct(int n) {
      int max1 = -1, max2 = -1;

      while(n>0){
        int modulus = n % 10;
        n = n/10;
        
        if(modulus >= max1){
            max2 = max1;
            max1 = modulus;
        }else{
            max2 = max(modulus, max2);
        }         
      }

      return max1 * max2;
    }
};