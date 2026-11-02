class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, pair<bool, bool>> mp;

        for (char c : word) {
            if (islower(c)) {
                mp[c].first = true;
            } else if (isupper(c)) {
                char lw = tolower(c);
                mp[lw].second = true;
            }
        }
        int count = 0;
        for (auto const& [key, flag] : mp) {
            if (flag.first && flag.second)
                count++;
        }
        return count;
    }
};

//https://leetcode.com/problems/count-the-number-of-special-characters-i/solutions/8294406/3120-count-the-number-of-special-charact-owhu/