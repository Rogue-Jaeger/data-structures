#include<bits/stdc++.h>
using namespace std;

bool solve(int arr[],int gilasum ,int milasum , int coins , int curr){
        //cout<<gilasum<<" "<<milasum<<endl;
        if(milasum > gilasum) return false;
        if(gilasum == milasum) return true;

        for(int i = curr ; i < coins ; i++){
                if(solve(arr,gilasum-arr[i],milasum+arr[i],coins,i+1) == true) return true;
        }

        return false;
}

int main(){
        //freopen("input.txt" , "r" , stdin);
        int test;
        cin>>test;

        while(test--){
                int coins,mila;
                cin>>coins>>mila;
                int arr[coins];
                int sum = 0;
                for(int i = 0 ; i<coins ; i++){
                        cin>>arr[i];
                        sum += arr[i];
                }
                //sort(arr,arr+coins);  most imp how to sort an array, showing time limit due to sorting

                if(sum < mila) cout<<0<<endl;
                else if(sum == mila) cout<<1<<endl;
                else{
                        // int index;
                        // for(int i = 0 ; i<coins; i++) if( arr[i] > int(sum-mila)/2 ) {index = i; break;}
                        // int arr2[index];
                        // for(int i = 0 ; i<index; i++) arr2[i] = arr[i];

                        if(abs(sum-mila)%2 != 0) cout<<0<<endl;
                        else (solve(arr,sum,mila,coins,0) == true) ? cout<<1<<endl : cout<<0<<endl;
                }
        }

}
