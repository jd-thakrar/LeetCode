class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<bool> pair(2048 , false);
        int n = nums.size();

        for(int i = 0; i< n; i++){
            for(int j =0 ;j<n; j++){
                int xorpair = nums[i] ^ nums[j];
                pair[xorpair] = true;
            }
        }

        vector<bool> pair2(2048 , false);

        for(int i = 0; i<2048 ; i++){

            if(!pair[i]) continue;

            for(int j = 0; j<n;j++){
                int xorpair = i ^ nums[j];
                pair2[xorpair] = true;
            }
        }
        int count = 0;
        for(int i = 0; i<2048; i++){
            if(pair2[i]){
                count++;
            }
        }
        return count;  
    }
};