//line sweep
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        map<int, int> event;
        for(auto &trip : trips){

            int count = trip[0];
            int start = trip[1];
            int end = trip[2];

            event[start] += count;
            event[end] -= count;
        }

        int passcount = 0;

        for(auto &it : event){

            passcount += it.second;

            if(passcount > capacity){
                return false;
            }
        }

        return true;
    }
};


//Defrence array technique
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int diff[10001] = {0};
        for(auto &trip : trips){

            int count = trip[0];
            int start = trip[1];
            int end = trip[2];

            diff[start] += count;
            diff[end] -= count;
        }

        int cumSum = 0;

        for(int i = 0 ; i < 1001 ; i++){
            cumSum += diff[i];

            if(cumSum > capacity){
                return false;
            }
        }
    
        return true;
    }
};

//reerence vedio: https://www.youtube.com/watch?v=E0g0QTwYK6g