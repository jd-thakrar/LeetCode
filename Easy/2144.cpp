
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int count = 0 , sum = 0;
        for(int i = cost.size()-1; i>=0; i--){
            if(count == 2){
                count = 0;
                continue;
            }
            count++;
            sum += cost[i];
        }
        return sum;
    }
};

//https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/solutions/8305765/2144-minimum-cost-of-buying-candies-with-rb65