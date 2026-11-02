#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // code here
    for(int i=0; i<n;i++){
        for(int k=0;k<i;k++){
            cout<<" ";
        }
        
        for(int j=i; j<(n*2)-i-1;j++){
            cout<<"*";
        }
        cout<<"\n";
    }

    return 0;
}