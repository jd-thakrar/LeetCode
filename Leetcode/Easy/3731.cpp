class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        map<int, int> fq;
        vector<int> ans;
        int maxnum = INT_MIN;
        int minnum = INT_MAX;
        for(int i : nums ){
            fq[i]++;
            maxnum = max(i ,maxnum); 
            minnum = min(i, minnum);
        }
        for(int i = minnum; i<=maxnum; i++){
            if(fq[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};