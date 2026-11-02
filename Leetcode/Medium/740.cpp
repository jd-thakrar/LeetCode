class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(),nums.end());
        vector<int> freq(maxVal+1, 0);

        for(int i = 0 ; i < nums.size(); i++){
            freq[nums[i]] += nums[i];
        }
        int res;
        for(int i = 2; i < maxVal+1; i++){
            freq[i] = max(freq[i-1], freq[i-2]+freq[i]);
        }
        return freq[maxVal];
    }
};