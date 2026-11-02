
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int mid = n/2;

        sort(begin(s), begin(s) + mid);

        int i = 0;
        int j = n-1;
        while(i<=j){
            s[j] = s[i];
            i++;
            j--;
        }
        return s;
    }
};