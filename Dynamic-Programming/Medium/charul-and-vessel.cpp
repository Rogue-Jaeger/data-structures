#include <bits/stdc++.h>
using namespace std;

//case 1 added due to this test case
// 15 77
// 74 21 72 94 21 74 35 68 30 21 89 59 45 94 40

int main() {
        int test;
        cin>>test;

        while(test--){

                int n , k;
                cin >> n >> k;

                int dp[k+1][n+1] , arr[n];

                for(int i = 0 ; i < n ; i++){
                        cin >> arr[i];
                }

                for(int i = 0 ; i<=k ; i++){
                        for(int j = 0 ; j<=n ; j++){

                                if(i == 0 ){
                                        dp[i][j] = 1; continue;
                                }
                                if(j == 0){
                                        dp[i][j] = 0; continue;
                                }

                                if(dp[i][j-1] == 1){
                                        dp[i][j] = 1; continue;
                                }
                                int mod = i % arr[j-1];
                                if(mod == 0){
                                        dp[i][j] = 1; continue;
                                }
                                else{
                                        if(dp[mod][j-1] == 1){
                                                dp[i][j] = 1; continue;
                                        }
                                }
                                /*case 1*/if( i-arr[j-1] >= 0 && dp[i-arr[j-1]][n] == 1 ){
                                        dp[i][j] = 1; continue;
                                }

                                dp[i][j] = 0;
                        }

                }
                cout<<setw(3)<<" ";
                cout <<setw(3) << dp[k][n];
                for(int i = 0 ; i<n ; i++){
                        cout<< setw(3) << arr[i];
                }cout<<endl;
                for(int i = 0 ; i<=k ; i++){
                        cout<< setw(3) <<i;
                        for(int j = 0; j<=n ; j++){
                                cout<<setw(3)<<dp[i][j];
                        }
                        cout<<endl;
                }
        }



        return 0;

}
