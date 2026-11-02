class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (char c : s) {
            if (c != '*' && c != '%' && c != '#') {
                result += c;
            }
            if (c == '*' && !result.empty()) {

                result.pop_back();
            }
            if (c == '#') {
                result += result;
            }
            if (c == '%') {
                reverse(result.begin(), result.end());
            }
        }
        return result;
    }
};