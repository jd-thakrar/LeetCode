class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), count = 0;
        int found = -1, found2 = -1, found3 = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') 
                found = i;
            else if (s[i] == 'b')
                found2 = i;
            else if (s[i] == 'c')
                found3 = i;

            if (found != -1 && found2 != -1 && found3 != -1)
                count += 1 + min({found,found2,found3});
        }
        return count;
    }
};