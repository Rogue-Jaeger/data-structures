#include<bits/stdc++.h>
using namespace std;

#define M 1000000007

//  below code is right for row<12 || col<12 cause after that the value becomes greater than 1000000007 and we divide that by 2 so we dont get
// accurate results

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


//                    this code is good cause it doesnt include any division or multiplication


int numberOfPaths(int m, int n)
{
    // Create a 2D table to store results of subproblems
    int count[m][n];

    // Count of paths to reach any cell in first column is 1
    for (int i = 0; i < m; i++)
        count[i][0] = 1;

    // Count of paths to reach any cell in first column is 1
    for (int j = 0; j < n; j++)
        count[0][j] = 1;

    // Calculate count of paths for other cells in bottom-up manner using
    // the recursive solution
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)

            // By uncommenting the last part the code calculatest he total
            // possible paths if the diagonal Movements are allowed
            count[i][j] = ( count[i-1][j] + count[i][j-1] ) % M;        

    }
    return count[m-1][n-1];
}
