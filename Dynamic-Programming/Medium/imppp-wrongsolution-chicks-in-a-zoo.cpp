// https://practice.geeksforgeeks.org/problems/chicks-in-a-zoo/0

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 1000000007

// wrong solution cause complexity created at 2*6+1 value difference starts occouring.

int main(){
        ll test , num;
        cin>>test;

        ll arr[36];
        arr[0] = 1;

        for(int i = 1 ; i < 36 ; i++ ){
                if(i-7 >= 0){
                        arr[i] = 3*(arr[i-1] - 2*(arr[i-6]/3));
                }
                else if(i-6 >= 0){
                        arr[i] = ( arr[i-1] - arr[i-6] ) * 3;
                }
                else{
                        arr[i] = arr[i-1]*3;
                }
                //cout << arr[i] << endl;
        }

        while(test--){
                cin >> num;
                cout << arr[num-1] << endl;
        }
}
