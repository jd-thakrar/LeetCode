class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size(),coin=coins,i=0,ans=0;
        sort(costs.begin(), costs.end());
        while(i<n){
            if(costs[i] <= coin ){
                coin -= costs[i];
                ans++;
            }
            i++;
        }
        return ans;
    }
};