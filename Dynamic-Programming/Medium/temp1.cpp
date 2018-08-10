#include <bits/stdc++.h>
using namespace std;


int main(){
        int test , tofind , size;
        //freopen("input.txt" , "r" , stdin);
        cin >> test;

        while(test--){
                cin >> size;
                int arr[size];
                for(int i = 0 ; i < size ; i++) cin >> arr[i];
                cin >> tofind;

                if(arr[0] < arr[size-1]) cout <<  find(arr  , 0 , size-1 , tofind) << endl;
                else{
                        int index = solve(arr , 0 , size-1);
                        if(tofind >= arr[0]) cout << find(arr , 0 , index , tofind) << endl;
                        else cout << find(arr , index+1 , size-1 , tofind) << endl;
                }
        }
}
https://ide.geeksforgeeks.org/index.php
https://www.geeksforgeeks.org/minimum-number-of-squares-whose-sum-equals-to-given-number-n/
https://practice.geeksforgeeks.org/problems/get-minimum-squares/0/?ref=self
