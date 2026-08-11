class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int, bool> mp;
        int n= nums.size();
        for(int i = 0; i<n;i++){
            mp[nums[i]] = true;
        }
        int sum =nums[0];
        for(int i = 1; i<n ;i++){
            if(nums[i-1]+1 == nums[i]){
                sum += nums[i];
              
            }else{
                break;
            }
        }
        while(mp.find(sum) != mp.end())
            sum +=1;
        
        return sum;
    }
};