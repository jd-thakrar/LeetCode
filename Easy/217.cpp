class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> element;
        for(int i : nums){
            if(element.find(i) != element.end())
                return true;

        element.insert(i);
        }
        return false;
    }
};