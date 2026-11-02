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
	bool isSumOfTwo(int n) {
		// code here
		set<int> arr;
		for (int i = 2; i<n; i++) {
			if (Prime(i)) {
				arr.insert(i);
			}
		}
		for (int num : arr) {
			int digit = n - num;
			if (arr.find(digit) != arr.end()) {
				return true;
			}
		}
		return false;
	}
};
