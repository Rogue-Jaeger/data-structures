// https://practice.geeksforgeeks.org/problems/geek-and-his-binary-strings/0

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 1000000007


void solve(ll num , ll one , ll zero , ll &res){
        if( zero > one ) return;
        if( one == num || one+zero == 2*num ){
                if( one >= zero ){
                        // cout<<one << " " <<zero <<endl;
                        res++;
                        return;
                }
                else return;
        }

        solve(num , one+1 , zero , res);
        solve(num , one , zero+1 , res);
}

int main(){
        ll test , num , res;
        cin>>test;

        while(test--){
                cin>>num;
                res = 0;
                solve( num , 0 , 0 , res );
                cout<<res<<endl;
        }
}
