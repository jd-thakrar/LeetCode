//Brute Force
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     int n = nums1.size()-1;
     double res;

     nums1.insert(nums1.end(), nums2.begin(), nums2.end());

     sort(nums1.begin(), nums1.end());
     n = nums1.size();

     if(n%2 == 0){
        int i = (n-1)/2;
        res = (nums1[i] + nums1[i+1])/2.0;
     }
     else{
        int i = n/2;
        res = nums1[i];
     }
     return res;  
    }
};