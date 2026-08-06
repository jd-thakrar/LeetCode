class Solution {
public:
    int smallestNumber(int n, int t) {
        int digit, ans;
        for (int i = n; i <= n + 9; i++) {
            int temp = i, num = 1;
            while (temp > 0) {
                digit = temp % 10;
                temp /= 10;
                num = digit * num;
            }
            if (num % t == 0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};