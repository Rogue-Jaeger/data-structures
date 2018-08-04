// https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers/0

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 1000000007


int main(){
        ll test , num ;
        cin>>test;


        ll arr[36];
        arr[0] = 1;
        for(int i = 1 ; i < 36 ; i++){
                arr[i] = arr[i-1]*2 + arr[i-1];
                if( i-6 >= 0 ) arr[i] = arr[i] - arr[i-6];
        }

        while(test--){
                cin >> num;
                cout << arr[num-1] << endl;
        }
}
