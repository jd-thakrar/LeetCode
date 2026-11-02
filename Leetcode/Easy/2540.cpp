class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int l = 0, r = m-1, mid= 0;
        for(int i=0; i<n; i++){
            l=0,r=m-1;
            while(l<=r){

                mid = l+(r-l)/2;

                if(nums1[i]==nums2[mid]){
                    return nums1[i];
                }else if(nums2[mid]>nums1[i]){
                    r=mid-1;
                }else{
                    l = mid+1;  
                }
            }
        }

        return -1;
    }
};