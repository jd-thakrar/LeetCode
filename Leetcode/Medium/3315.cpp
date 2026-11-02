class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        vector<int> result;
        bool found = false;

        for( int i = 0; i < nums.size(); i++){

            if(nums[i]%2 == 0){
                result.push_back(-1);
                continue;
            }
            for(int j = 1; j < 32; j++){
                
                if((nums[i] & (1<<j)) > 0){
                    continue;
                }

                int prev = j - 1;
                int x = (nums[i] ^ (1 << (j-1)));
                result.push_back(x);
                found = true;
                break;
            }
            if(found == false){
                result.push_back(-1);
            }
        }
        return result;
    }
};

//Refrence: https://www.youtube.com/watch?v=RnCZCzFivl8