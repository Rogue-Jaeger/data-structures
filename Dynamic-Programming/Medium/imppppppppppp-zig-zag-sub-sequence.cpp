#include<bits/stdc++.h>
using namespace std;

// good test cases are (1 10 7 1) (1 10 100 90 80 90) see by making a graph the we have to count the vertices 

int solve(int arr[] , int size){

        int poscount = 1 , negcount = 1;

        for(int i = 1 ; i < size ; i++){
                if( arr[i] > arr[i-1] ) poscount = negcount + 1; // cause neg wala hamesha hi neg pe khatam hoga
                else if( arr[i] < arr[i-1] ) negcount = poscount + 1;
        }

        return max(negcount , poscount);
}


int main() {
        int t , num;
        cin>>t;

        while(t--)
        {
                cin >> num;
                int arr[num];

                for(int i = 0 ; i < num ; i++){
                        cin >> arr[i];
                }

                cout << solve(arr , num) << endl;

        }
        return 0;
}
