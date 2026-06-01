class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long sum = mass, diff;
        for(int i = 0; i<asteroids.size();i++){
            diff = sum - asteroids[i];
            if(diff >= 0){
                sum += asteroids[i];
                continue;
            }
            return false;
        }
        return true;
    }
};