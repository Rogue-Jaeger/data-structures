#include <bits/stdc++.h>
using namespace std;

#include <iostream>
using namespace std;

void solve(string str){
    long long res = 0;
    int arr[str.size()];
    arr[0] = 1;

    for(int i = 1; i<str.size() ; i++){
        if(i%2 == 1){
            if(str.substr(0 , i/2+1) == str.substr(i/2+1 , i/2+1)){
                arr[i] = min( arr[i-1]+1 , arr[i/2]+1);
            }
            else{
                arr[i] = arr[i-1]+1;
            }
        }
        else{
            arr[i] = arr[i-1]+1;
        }
    }

    //for(int i = 0 ; i<str.size() ; i++) cout<<arr[i]<<" ";
    cout << arr[str.size()-1] << endl;
}

int main() {
    long long test;
    cin >> test;

    while(test--){
        string str;
        cin>>str;
        solve(str);
    }

	return 0;
}
