class Solution {
	public:
	void printDiamond(int n) {
		// code here
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n-i-1; j++) {
				cout << " ";
			}
			for (int k = 0; k <= i; k++) {
				cout << " *";
			}
			cout << "\n";
		
		}
		for (int i = 0; i<n; i++) {
		   for (int j = 0; j<i; j++) {
				cout << " ";
			}
			for (int k = n-i; k > 0; k--) {
				cout << " *";
			}
			cout<<"\n";
		}
		

	}
};
//https://www.geeksforgeeks.org/problems/pattern/1