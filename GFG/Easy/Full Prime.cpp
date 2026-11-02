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
	
	
	int fullPrime(int N) {
		// code here
		int X=N;
		bool isok = true;
		while(N > 0){
		    int digit = N%10;
		    isok = Prime(digit);
		    if(isok == false){
		        break;
		    }
            N/=10;
		}
		
		if(Prime(X) && isok){
		    return 1;
		}else{
		    return 0;
		}
		
	}
};
