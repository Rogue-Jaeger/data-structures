#include <iostream>
using namespace std;

long long solve(int arr[] , int num){

    long long dp[num] = {0};
    dp[0] = arr[0]; dp[1] = max(arr[0] , arr[1]);

    for(int i = 2 ; i < num ; i++){
        dp[i] = max( dp[i-1] , arr[i]+dp[i-2]);
    }

    return dp[num-1];
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
