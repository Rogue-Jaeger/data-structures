// https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array/0

#include <bits/stdc++.h>
using namespace std;



int find(int arr[] , int start , int end , int tofind){
        if(arr[start] == arr[end]) if(arr[start] == tofind) return start; else return -1;
        if( start >= end ) if(arr[start] == tofind) return start; else return -1;

        int mid = (start+end)/2;
        if( arr[mid] == tofind ) return mid;

        if( arr[mid] > tofind ) return find(arr , start , mid-1 , tofind);
        else return find(arr , mid+1 , end , tofind);

}

int solve(int arr[] , int start , int end , bool &found , int tofind){
        if(start >= end){
            if( arr[start] == tofind ) found = true ;
            return start;
        }

        int mid = (start+end)/2;
        if(arr[mid] == tofind){
            found = true;
            return mid;
        }

        if(arr[mid] > arr[start]){
                return solve(arr , mid , end , found , tofind);
        }
        else{
                return solve(arr , start , mid , found , tofind);
        }
}


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
                        bool found = false;
                        int index = solve(arr , 0 , size-1 , found , tofind);  // if the value gets found in the initiation phase itself then return from here
                        if(found){
                            cout <<  index << endl ;
                            continue;
                        }
                        if(tofind >= arr[0]) cout << find(arr , 0 , index , tofind) << endl;
                        else cout << find(arr , index+1 , size-1 , tofind) << endl;
                }
        }
}
