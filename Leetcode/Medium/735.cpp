class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < asteroids.size(); i++) {
            while (!st.empty() && asteroids[i] < st.top() && ((asteroids[i]>0 && st.top()<0) || (asteroids[i]<0 && st.top()>0) )) {
                if (abs(asteroids[i]) == st.top()) {
                    st.pop();
                    goto br;
                }
                if (abs(asteroids[i]) > st.top()) {
                    st.pop();
                } else {
                    goto br;
                }
            }
            st.push(asteroids[i]);
        br:
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};