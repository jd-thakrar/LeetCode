class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int sum = INT_MAX, startTime = INT_MIN , time = INT_MAX, t;
        int n = landStartTime.size(), m = waterStartTime.size();
        for( int i = 0; i<n ; i++){
            for( int j = 0; j<m; j++){
                t = landStartTime[i] + landDuration[i];
                startTime = max(t, waterStartTime[j]);
                time = min( time, startTime + waterDuration[j]);
                
                t = waterStartTime[j]+ waterDuration[j];
                startTime = max(t, landStartTime[i]);
                time = min(time, startTime + landDuration[i]);
            }
        }
     return time;
    }
};

//https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/solutions/8310400/3633-earliest-finish-time-for-land-and-w-qxxm