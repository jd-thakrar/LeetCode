class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), left = 0, right = n-1, mid;

        while(left < right){
            int mid = (left + right) / 2;
             if(nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};