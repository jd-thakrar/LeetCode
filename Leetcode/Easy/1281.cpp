class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int sum = 0 ,product = 1;
        while(n != 0){
            int digit = n%10;
            sum += digit;
            product *= digit;
            n = n/10;
        }   

        return product - sum;
    }
};

//https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/solutions/8540558/1281-subtract-the-product-and-sum-of-dig-nhht