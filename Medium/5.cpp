class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), l, r, len = 0, count = 0, start;
        string res;

        for (int i = 0; i < n; i++) {

            l = i, r = i;

            while ((l >= 0 && r < n) && s[l] == s[r]) {
                l--;
                r++;
            }
            count = (r - 1) - (l + 1) + 1;
            if (count > len) {
                start = l + 1;
                len = count;
            }

            l = i, r = i + 1;
            while ((l >= 0 && r < n) && s[l] == s[r]) {
                l--;
                r++;
            }
            count = (r - 1) - (l + 1) + 1;
            if (count > len) {
                start = l + 1;
                len = count;
            }
        }

        return s.substr(start, len);
    }
};