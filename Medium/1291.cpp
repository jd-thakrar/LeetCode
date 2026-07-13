class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num = "123456789";
        vector<int> ans;
        string l = to_string(low);
        int stin = l[0] - '1';
        int lowLen = to_string(low).size();
        int highLen = to_string(high).size();

        for (int len = lowLen; len <= highLen; len++) {
                for(int start = 0; start+len <= num.size() ; start++)
                {
                    int fnum = stoi(num.substr(start, len));
                    if(fnum>= low && fnum<=high){
                        ans.push_back(fnum);
                    }
                }
        }
        return ans;
    }
};