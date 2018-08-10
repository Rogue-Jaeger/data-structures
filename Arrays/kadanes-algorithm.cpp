//  https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

#include <bits/stdc++.h>
using namespace std;


int main(){
        int test , size;
        cin >> test;

        while(test--){
                cin >> size;
                int arr[size];
                for(int i = 0 ; i < size ; i++) cin >> arr[i];

                int val = 0 , maxval = INT_MIN;

                for(int i = 0 ; i < size ; i++){
                        val += arr[i];
                        if(val > maxval) maxval = val;
                        if(val < 0) val = 0;
                }

                cout << maxval << endl;
        }
}
