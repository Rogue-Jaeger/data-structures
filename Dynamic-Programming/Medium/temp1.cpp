#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

// Returns count of possible paths to reach cell at row number m and column
// number n from the topmost leftmost cell (cell at 1, 1)
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
                for (int j = 1; j < n; j++){

                        // By uncommenting the last part the code calculatest he total
                        // possible paths if the diagonal Movements are allowed
                        count[i][j] = ( count[i-1][j] + count[i][j-1] ) % M; //+ count[i-1][j-1];
                        cout <<setw(9)<< count[i][j] << " ";
                }
                cout<<endl;
        }
        return count[m-1][n-1];
}

// Driver program to test above functions
int main()
{
        int n , m;
        cin >> n >> m;
        cout << numberOfPaths(n, m);
        return 0;
}