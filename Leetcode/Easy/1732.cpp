class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int altitudes = 0;

        for(int i = 0; i< gain.size();i++){
            altitudes = gain[i]+altitudes;
            ans = max(ans, altitudes);
        }
        return ans;
    }
};