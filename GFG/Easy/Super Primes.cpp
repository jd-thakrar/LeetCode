class Solution {
  public:
    bool Prime(int n){
        if(n==2){return true;}
        if(n%2==0){return false;}
        if(n<=1){return false;}
        for(int i = 3; i<=sqrt(n);i+=2){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    vector<int> superPrimes(int n) {
        // code here
        vector<int> arr,ans;
        for(int i = 2;i<=n;i++ ){
            if(Prime(i)){ arr.push_back(i); }
        }
        int s = arr.size();
        for(int i =0; i<s ;i++){
            if(arr[i]<=s){
                int index = arr[i]-1;
                ans.push_back(arr[index]);
            }
        }
        
        return ans;
    }
};