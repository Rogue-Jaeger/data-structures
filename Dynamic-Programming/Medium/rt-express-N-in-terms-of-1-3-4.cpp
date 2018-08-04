#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 1000000007


void solve(ll arr[] ,int index , vector<ll> &dp ){
        if(index == dp.size()) return;

        for(int i = 0 ; i < 3 ; i++){
                if(  index - arr[i] >= 0 ) dp[index] += dp[index - arr[i]];
                dp[index] %= M;
        }
        solve(arr , index+1 ,  dp );
        return;
}

int main(){
        ll test , num , res;
        ll arr[] = {1,3,4};
        cin>>test;

        while(test--){
                cin>>num;
                res = 0;
                vector <ll> dp(num+1 , 0);

                for(int i = 0 ; i < 3 ; i++){
                        dp[arr[i]] = 1;
                }
                if(num<3){
                        cout<<dp[num]<<endl;
                        continue;
                }

                solve( arr , 0 , dp );
                cout << dp[num] << endl;
        }
}
