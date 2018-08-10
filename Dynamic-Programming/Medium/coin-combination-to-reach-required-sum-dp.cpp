#include <bits/stdc++.h>
using namespace std;


int main(){
        int test , val , size;
        freopen("input.txt" , "r" , stdin);
        cin >> test;

        while(test--){
                cin >> val >> size;
                int dp[val+1][size+1] , arr[size];
                for(int i = 0 ; i < size ; i++) cin >> arr[i];

                for(int i = 0 ; i <= val ; i++){
                        for(int j = 0 ; j <= size ; j++){
                                if(i == 0) dp[i][j] = 0;
                                else if(j == 0) dp[i][j] = INT_MAX;
                                else{
                                        if( i % arr[j-1] == 0 ){
                                                int quo = i/arr[j-1];

                                                int minval = min( dp[i][j-1] , quo );
                                                if( i - arr[j-1] >= 0 && dp[i-arr[j-1]][size] != INT_MAX ) minval = min( dp[i-arr[j-1]][size] + 1 , minval );

                                                dp[i][j] = minval;
                                        }
                                        else{
                                                int a;
                                                if( i-arr[j-1]>=0 && dp[i-arr[j-1]][size] != INT_MAX ) a = dp[i-arr[j-1]][size] + 1; else a = INT_MAX;
                                                int minval = min( dp[i][j-1] , a);
                                                dp[i][j] = minval;
                                        }
                                }

                        }
                }

                if( INT_MAX-4 < dp[val][size] ) cout << -1 << endl;
                else cout << dp[val][size] << endl;
        }
}
