class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        unordered_set<int> s;
        for (int x : nums) {
            if(s.find(x) != s.end()){
                ans = x;
                break;
            }
            s.insert(x);
        }
        return ans;
    }
};

//https://leetcode.com/problems/find-the-duplicate-number/solutions/8297053/287-find-the-duplicate-number-using-hash-ijyr