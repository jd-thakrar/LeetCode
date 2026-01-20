public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            bool found = false;
            for(int j = 0; j < nums[i]; j++){
                if((j | (j+1)) == nums[i]){
                    result.push_back(j);
                    found = true;
                    break;
                }
            }
            if(found == false){
                result.push_back(-1);
            }
        }
        return result;
    }
};

//Refrence: https://www.youtube.com/watch?v=RnCZCzFivl8class Solution {
//Brute force approach better approach is in Medium/3315.cpp