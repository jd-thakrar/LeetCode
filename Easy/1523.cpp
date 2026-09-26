class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        // for(int i = low; i <= high; i++){
        //     if(i%2 != 0){
        //         count++;
        //     }
        // }

        while(low<=high){
            if(low%2 != 0){
                count++;
            }
            low++;
        }
        return count;
    }
};

//https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/solutions/8540576/1523-count-odd-numbers-in-an-interval-ra-qj6u