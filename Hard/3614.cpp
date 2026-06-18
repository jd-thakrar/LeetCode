class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> len;
        int i = 0;

        long long count = 0;
        for (char c : s) {
            if (c != '*' && c != '#' && c != '%') {
                count += 1;
                len.push_back(count);
            }
            if (c == '#') {
                count *= 2;
                len.push_back(count);
            }
            if (c == '%') {
                len.push_back(count);
            }
            if (c == '*') {
                count = max(0LL, count - 1);
                len.push_back(count);
            }
            i++;
        }
        long long finlen = len.back();
        if (k >= finlen) {
            return '.';
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            long long currLen = len[i];
            long long oldLen = (i == 0 ? 0 : len[i - 1]);
            if (s[i] == '#') {
                k = k % oldLen;
            }
            if (s[i] == '%') {
                k = currLen - 1 - k;
            }
            if (s[i] >= 'a' && s[i] <= 'z') {
                if (k == oldLen) {
                    return s[i];
                }
            }
        }
        return '.';
    }
};