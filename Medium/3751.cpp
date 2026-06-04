class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int waveiness = 0;
        for(int num = num1; num<=num2; num++){
            string s = to_string(num);
            for(int i = 1; i<=(int)s.size()-2; i++){
                if((s[i]>s[i+1] && s[i]>s[i-1]) || (s[i]<s[i+1] && s[i]<s[i-1]))
                    waveiness++;
            }
        }
        return waveiness;
    }
};