#include <bits/stdc++.h>
using namespace std;

int main(){
        int test , size , num;
        cin >> test;

        while(test--){
                cin >> size;
                int arr[size];
                for(int i = 0 ; i < size ; i++) cin >> arr[i];
                cin >> num;
                int dp[num+1][size+1];

                for(int i = 0 ; i <= num ; i++){
                        for(int j = 0 ; j <= size ; j++){
                                if(j == 0) { dp[i][j] = 0; continue; }
                                if(i == 0) { dp[i][j] = 1; continue; }

                                int x, y;
                                x = (i-arr[j-1] >= 0) ? dp[i-arr[j-1]][j] : 0;  // we dont consider if 2 perfectly divides 6 and we dont consider dp[i][size]
                                y = dp[i][j-1];                                 // cause we only see upto that combination of 1 2 not 1 2 3
                                dp[i][j] = x + y;
                                //cout << dp[i][j] << " ";
                        }//cout << endl;
                }

                cout << dp[num][size] << endl;
        }

}
