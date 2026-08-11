class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());
        int n = discounts.size(), temp, m = prices.size();
        double ans = 0;
        for(int i = 0; (i<n && i<m) ;i++){
            ans += (prices[i] * (100 - discounts[i]))/100.0;
            temp = i;
        }
        temp += 1;
        n = prices.size();
        for(int j = temp; j<n; j++){
            ans += prices[j];
        }
        return ans;
    }
};