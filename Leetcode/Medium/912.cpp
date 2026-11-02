class Solution {
public:

    void merge(vector<int> &arr, int left, int mid, int right) {
        int i = left;    
        int j = mid + 1;  
        int k = 0;       

        vector<int> temp(right - left + 1,0);

        while (i <= mid && j <= right) {
            if (arr[i] < arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }

        while (i <= mid)
            temp[k++] = arr[i++];

        while (j <= right)
            temp[k++] = arr[j++];

        for (i = left, k = 0; i <= right; i++, k++)
            arr[i] = temp[k];
    }
    void mergesort(vector<int>& arr, int left, int right) {

        if (left >= right) return;
        int mid = (left + right) / 2;

        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergesort(nums, 0, n - 1);
        return nums;
    }
};