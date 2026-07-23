class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n < 3) return n;

        int bit = 0;
        while((1<<bit) <= n)
            bit++;

        return 1<<bit;
    }
};