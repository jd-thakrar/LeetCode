class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n = s.size(), count=0, i=0,res=0;
    vector<int> mp(256,-1);

  
    while(i<n){
        
        if(mp[s[i]]>-1){
            i=mp[s[i]]+1;
            mp[s[i]]=-1;

            res = max(count,res);
            count= 0;
             fill(mp.begin(), mp.end(), -1); 
            continue;
       }    
           mp[s[i]] = i;

       count++;
       i++;
    }
    return max(res,count);
    }
};