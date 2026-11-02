class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size(), sum = 0, count = 0;
        long long whnum = 0;
        long long MOD = 1000000007;
        vector<int> prefix;
        vector<int> numnonzero;
        vector<long long> num;

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }


        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';
            sum += digit;
            prefix.push_back(sum);
            if (digit != 0)
                whnum = (whnum * 10 + digit)  % MOD;

            if (i == 0 && digit == 0) {
                numnonzero.push_back(0);
                num.push_back(0);
            } else if (i == 0 && digit != 0) {
                numnonzero.push_back(1);
                num.push_back(digit);
            } else if (digit == 0) {
                numnonzero.push_back(numnonzero.back());
                num.push_back(num.back());
            } else {
                numnonzero.push_back(numnonzero.back() + 1);
                num.push_back(whnum);
            }
        }
        vector<int> ans;
        for(int i = 0; i<queries.size();i++){
            int f = queries[i][0];
            int sec = queries[i][1];


            long long fsum = prefix[sec] - (f > 0 ? prefix[f - 1] : 0);;
            int nzero = numnonzero[sec] -  (f > 0 ? numnonzero[f - 1] : 0);
            long long left_part = (f > 0 ? num[f - 1] : 0);
            long long fnum = (num[sec] - (left_part * pow10[nzero]) % MOD + MOD) % MOD;
            long long fans = fsum * fnum;
    
            ans.push_back(fans % MOD);
        }
        return ans;
    }
};