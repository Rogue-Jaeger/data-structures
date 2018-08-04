// https://practice.geeksforgeeks.org/problems/chicks-in-a-zoo/0

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 1000000007


int main(){
        ll test , num;
        cin>>test;

        ll arr[36];
        arr[0] = 1;

        for(int i = 1 ; i < 36 ; i++ ){
                if(i-7 >= 0){
                        arr[i] = 3*(arr[i-1] - 2*(arr[i-6]/3)); // see this was the formula he used to calculate
                }                                               // we can learn form this is try to refrain from arr[i-6] - arr[i-7] try to raplace it with one of them
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
