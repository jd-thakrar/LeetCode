
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<int> srtarr(arr);
        sort(srtarr.begin(), srtarr.end());
        unordered_map<int , int> mp;

        for(int i : srtarr){
            if(!mp.count(i)){
                mp[i] = mp.size() + 1;
            }
        }
        for(int i = 0; i<arr.size(); i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};