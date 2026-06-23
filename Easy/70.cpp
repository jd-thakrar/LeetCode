class Solution {
public:
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        int prev1 = 1;
        int prev2 = 2;
        int i=2, cur;
        while(i<n){
            cur = prev1+prev2;
            prev1 = prev2;
            prev2 = cur;
            i++;
        }
        return prev2;
    }
};