// https://practice.geeksforgeeks.org/problems/check-if-any-valid-sequence-is-divisible-by-m/0


#include <bits/stdc++.h>
using namespace std;

#define MAX  10000

bool solve(int arr[] ,int totalsize , int divisor , int index  , int sum , int dp[][MAX]/* see how dp is declared*/){
        if(index == totalsize){
                if(sum % divisor == 0) return true;
                else return false;

        }

        if(dp[index][sum] != -1){ // we took -1 cause 0 will be false 1 will be true and -1 will be combination not occoured before
                //cout << arr[index] << " " << sum <<endl;
                if(dp[index][sum] == 1) return true;
                else return false;
        }


        bool left = solve(arr , totalsize , divisor , index+1 , sum+arr[index] , dp);
        bool right = solve(arr , totalsize , divisor , index+1 , sum-arr[index] , dp);

        bool res = (left || right);
        dp[index][sum] = res;

        return res;
}

int main(){
        int test;
        cin>> test;

        while(test--){
                int size;
                cin>>size;

                int arr[size];

                for(int i = 0 ; i< size ; i++){
                        cin>>arr[i];
                }

                int divisor;
                cin >> divisor;

                int dp[size][MAX]; // declared int to accomodate -1, 0 and 1
                memset(dp , -1 , sizeof(dp));

                bool res = solve(arr , size , divisor , 0 , 0 , dp );

                cout<<res<<endl;
        }
}
