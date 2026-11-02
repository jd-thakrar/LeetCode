class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size(), count = 0;
        string res="";

        if(n==1){
            return strs[0];
        }
        for (int i = 0; i < m; i++) {
            count = 0;
            for (int j = 0; j < n-1; j++) {
                
                if (strs[j][i] == strs[j + 1][i]) {
                    count++;
                }else{
                    return res;
                }

                if (count == n-1) {
                    res += strs[j][i];
                }
            }
            
        }
        return res;
    }
};

//https://leetcode.com/problems/longest-common-prefix/solutions/8254074/14-longest-common-prefix-by-thakrar_jeet-rgrl