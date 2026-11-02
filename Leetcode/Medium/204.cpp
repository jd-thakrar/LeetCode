class Solution {
public:
     bool Prime(int n){
	    if(n==2){return true;}
	    if (n<=1) {return false; }
		if(n%2 == 0) {return false; }
		for (int i = 3; i<=sqrt(n); i+=2) {
			if (n%i == 0) {
				return false;
			}
		}
		return true;
	}
    int countPrimes(int n) {
           // code here
        int count =0;
        if(n<3){return 0;}
        for(int i = 2; i<n; i++){

            if(Prime(i)){
                count++;
            }
        }
        return count;
    }
};