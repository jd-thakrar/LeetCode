class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n%2 == 0){
            return n;
        }else{
            return n*2;
        }
    }
};

//https://leetcode.com/problems/smallest-even-multiple/solutions/8540553/2413-smallest-even-multiple-by-thakrar_j-ihjt