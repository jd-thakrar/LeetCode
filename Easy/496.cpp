class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        int n = nums2.size(),m= nums1.size();
        vector<int> ans( m,-1);
        for(int i = 0; i<n; i++){
            while(!st.empty() && nums2[i] > st.top()){
                
                mp[st.top()] = nums2[i];
                st.pop();   
            }
            st.push(nums2[i]);
        }
        for(int i = 0; i<m;i++){
            int key = nums1[i];
            ans[i] = mp.count(key) ? mp[key] : -1;
        }
        return ans;
    }
};