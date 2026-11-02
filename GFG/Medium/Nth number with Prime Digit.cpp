class Solution {
	public:
	bool Prime(int n) {
		if (n == 2) {return true; }
		if (n%2 == 0) {return false; }
		if (n <= 1) {return false; }
		for (int i = 3; i <= sqrt(n); i += 2) {
			if (n%i == 0) {
				return false;
			}
		}
		return true;
	}
	int primeDigits(int n) {
		// code here
		int count = 0;
		int i = 2;
		int ans = 0;
		while (count != n) {
			int j = 0, cn = 0;
			int x = i;
			while (x>0) {
				cn++;
				int digit = x%10;
				if (Prime(digit)) {j++; }
				x /= 10;
			}
			if (j == cn) {ans = i; count++; }
			
			i++;
		}
		return ans;
	}
};
