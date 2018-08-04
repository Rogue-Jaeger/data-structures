#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// this sol is wrong cause it will not include the case for 3 1 cause the arrindex is going only upwards

void solve( ll index , ll arr[] , ll n , ll num , ll &res , ll sum ){
        if(sum >= num || index >= n){
                if(sum == num){
                        res++;
                        //cout<<arr[index]<<" ";
                        return;
                }
                else return;
        }
        //cout<<arr[index]<<" ";
        solve(index , arr , n ,  num , res , sum + arr[index] );
        //cout<<endl<<arr[index]<<" ";
        solve(index+1 , arr , n , num , res , sum + arr[index] );
        //cout<<endl;
}

int main(){
        ll test , num , res;
        ll arr[] = {1,3,4};
        cin>>test;

        while(test--){
                cin>>num;
                res = 0;
                solve(0 , arr , 3 , num , res , 0);
                cout << res << endl;
        }
}
