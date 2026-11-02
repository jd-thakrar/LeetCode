class Solution {
  public:
    bool Prime(int n){
	    if(n==2){return true;}
	    if (n<3) {return false; }
		if(n%2 == 0) {return false; }
		for (int i = 3; i<n/2; i++) {
			if (n%i == 0) {
				return false;
			}
		}
		return true;
	}
    
    int nextPrime(int n) {
        // code here
        int i = n;
        while(i<=INT_MAX){
          i = i+1;
          if(Prime(i)){
              return i;
          }
        }
    }
};