
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

    vector<int> arr(5);
    
    cout<<"Enter 5 numbers: \n";
    for(int i = 0; i<5; i++){
        cin>>arr[i];
    }

    cout<<"\n\nOutput \n";
    
    vector<int> ans;
    ans.push_back(arr[4]);
    for(int i = 0; i<4;i++){
        ans.push_back(arr[i]);
    }


    // std::reverse(arr.begin(), arr.end());
    // std::reverse(arr.begin()+1, arr.end());

    for(int i = 0; i<5;i++){
        cout<<arr[i]<<"\n";
    }
    return 0;

   
}