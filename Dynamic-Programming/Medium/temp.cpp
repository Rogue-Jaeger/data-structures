#include<bits/stdc++.h>
using namespace std;

// find max LIS and substract the rest

#define M 1000000007


int main() {
        int t , row , col;
        cin>>t;

        while(t--)
        {
                cin >> row >> col;
                if(row == 1 || col == 1) return 1;

                long long arr[row][col];

                for(int i = 0 ; i < row ; i++){ //cout << endl;
                        for(int j = 0 ; j<col ; j++){
                                if(i == row-1 && j == col-1) arr[i][j] = ( arr[i-1][j] + arr[i][j-1] ) ;
                                else if(i == 0 && j < col-1 || j == 0 && i < row-1 ) arr[i][j] = 2;
                                else if( i == 0 && j == col-1 || j == 0 && i == row-1 ) arr[i][j] = 1;
                                else if( i == row-1 ) arr[i][j] = ( arr[i][j-1] + arr[i-1][j]/2 ) ;
                                else if( j == col-1 ) arr[i][j] = ( arr[i][j-1]/2 + arr[i-1][j] ) ;
                                else arr[i][j] = ( arr[i-1][j] + arr[i][j-1] ) ;
                                //cout <<setw(9)<< arr[i][j] << " ";
                        }
                }

                cout <<  arr[row-1][col-1]%M << endl;

        }
        return 0;
}
