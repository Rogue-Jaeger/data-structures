#include<bits/stdc++.h>
using namespace std;

// find max LIS and substract the rest

int solve(int arr[] , int size){
        int dp[size];
        int maxlen = 1;  // not zero cause it will fail the test case 1 10

        for(int i = 0 ; i < size ; i++){
                dp[i] = 1;
        }

        for(int i = 1 ; i < size ; i++ ){
                for(int j = 0 ; j < i ; j++){
                        if(arr[i] > arr[j]) dp[i] = max(dp[i] , dp[j] + 1);
                }
                maxlen = max(maxlen , dp[i]);  // see how he used len
        }

        return size - maxlen;
}


int main() {
        int t , num;
        cin>>t;

        while(t--)
        {
                cin >> num;
                int arr[num];

                for(int i = 0 ; i < num ; i++){
                        cin >> arr[i];
                }

                cout << solve(arr , num) << endl;

        }
        return 0;
}
