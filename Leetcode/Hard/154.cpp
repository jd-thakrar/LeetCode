class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1, left = 0, right = n, mid = 0;

        while (left < right) {

            mid = (left + right) / 2;

            if (nums[mid] > nums[right]){
                left = mid + 1;
            }
            else if (nums[mid] == nums[right]){
                right--;
            }
            else{
                right = mid;
            }
        }
        return nums[left];
    }
};

//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/solutions/8247728/find-minimum-in-rotated-sorted-array-ii-jbhgq