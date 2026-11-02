class Solution {
public:
    bool checkDivisibility(int n) {
        int mul = 1;
        int sum = 0;
        int num = n;
        while(num>0){
            int digit = num%10;
            mul *= digit;
            sum += digit;
            num /= 10; 
        }   

        return (n%(mul+sum)) == 0?true:false;
    }
};