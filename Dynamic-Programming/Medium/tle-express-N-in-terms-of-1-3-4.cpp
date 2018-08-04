#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// agar index wala system wrong lage to index rakho hi mat

void solve( ll arr[] , ll n , ll num , ll &res , ll sum ){

        if(sum == num){
                res++;
                return;
        }

        for(int i = 0; i < n ; i++){
                if( sum <= num ){
                        solve(arr , n , num , res , sum + arr[i]);
                }
                else return;
        }

        return;
}

int main(){
        ll test , num , res;
        ll arr[] = {1,3,4};
        cin>>test;

        while(test--){
                cin>>num;
                res = 0;
                solve( arr , 3 , num , res , 0);
                cout << res << endl;
        }
}
