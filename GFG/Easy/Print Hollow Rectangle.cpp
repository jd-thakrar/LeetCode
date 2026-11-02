class Solution {
	public:
	void printHollowRect(int n, int m) {
		// code here
		for (int i = 0; i<n; i++) {
			if (i == 0 || i == n - 1) {
				for (int j = 0; j<m; j++) {
					cout << "*";
				}
			}
			else {
				for (int j = 0; j<m; j++) {
					if (j == 0 || j == m-1) {
						cout << "*";
					} else {
						cout << " ";
					}
				}
			}
			cout<<"\n";
		}
	}
};
//https://www.geeksforgeeks.org/problems/hollow-rectangle-or-square/1