class Solution {
public:
    void swap(int& n, int& m) {
        int temp = n;
        n = m;
        m = temp;
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size() - 1, left = 0, right = n, mid = 0;

        while (mid <= right) {

            if (nums[mid] == 0) {
                swap(nums[mid], nums[left]);
                left++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[right]);
                right--;
            }
        }
    }
};

//https://leetcode.com/problems/sort-colors/solutions/8250636/75-sort-colors-by-thakrar_jeet-fyyn