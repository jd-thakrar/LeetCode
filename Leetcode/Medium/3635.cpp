class Solution {
public:
    int findtime(vector<int> actsrt1, vector<int> actdur1, vector<int> actsrt2, vector<int> actdur2){
        int finish1 = INT_MAX;
        for(int i = 0; i<actsrt1.size();i++){
            finish1 = min(finish1, actsrt1[i]+actdur1[i]);
        }
        int finish2 = INT_MAX;
        for(int i = 0; i<actsrt2.size();i++){
            finish2 = min(finish2, max(finish1, actsrt2[i])+actdur2[i]);
        }

        return finish2;
        
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
            int FLTW = findtime(landStartTime,landDuration,waterStartTime,  waterDuration);
            int FWTL = findtime(waterStartTime,  waterDuration, landStartTime, landDuration);
            return min(FLTW, FWTL);
    }
};


//https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/solutions/8312606/3635-earliest-finish-time-for-land-and-w-3898