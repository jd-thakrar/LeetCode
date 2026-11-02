//Using Unordered Set
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


//Using Slow Fast Pointers
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast= nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        slow = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
//https://leetcode.com/problems/find-the-duplicate-number/solutions/8297053/287-find-the-duplicate-number-using-hash-ijyr
//https://leetcode.com/problems/find-the-duplicate-number/solutions/8297095/287-find-the-duplicate-number-using-link-hp5r