class Solution {
  public:
    bool isPrime(int n) {
        // code here
        if(n<3){return false;}
        if(n%2 == 0){return false;}
        for(int i = 3; i<n/2; i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
};
