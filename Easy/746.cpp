class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1 = cost[0];
        int prev2 = cost[1];
        int i = 2;
        int cur;
        while(i<cost.size()){
            cur = cost[i] + min(prev2, prev1);
            prev1 = prev2;
            prev2=cur;
            i++;
        }

        return min(prev1,prev2);      
    }
};