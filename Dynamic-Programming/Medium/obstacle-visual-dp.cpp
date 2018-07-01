// https://leetcode.com/problems/unique-paths-ii/description/

//                      code which ran for 3 ms used only 1d array instead of 2d
// static int x = [](){
//     std::ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     return 0;
// }();
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         vector<int> result( obstacleGrid.size() + 1, 0 );
//         int m = obstacleGrid.size() - 1;
//         int n = obstacleGrid[0].size() - 1;
//
//         result[m] = 1;
//
//         for( int j = n; j >= 0; j-- )
//         {
//             for( int i = m; i >= 0; i-- )
//             {
//                 if ( obstacleGrid[i][j] == 1 )
//                     result[i] = 0;
//                 else
//                     result[i] += result[i + 1];
//             }
//         }
//
//         return result[0];
//     }
// };






#include<iostream>
using namespace std;

int main(){
        freopen("input.txt", "r" , stdin);
        int row,col;
        cin>>row>>col;

        int arr[row][col] = {0};
        int inputarr[row][col];

        for(int i = 0 ; i<row ; i++){
                for(int j = 0 ; j<col ; j++){
                        cin>>inputarr[i][j];
                }
        }


                for(int i = 0 ; i<row ; i++){
                        for(int j = 0 ; j<col ; j++){
                                cout<<inputarr[i][j]<<" ";
                        }
                        cout<<endl;
                }

                cout<<endl;

                for(int i = 0 ; i<row ; i++){
                        for(int j = 0 ; j<col ; j++){
                                arr[i][j] = 0;
                                cout<<arr[i][j]<<" ";
                        }
                        cout<<endl;
                }
                cout<<endl;


        for(int i = 0; i<row ; i++){
                for(int j = 0 ; j<col ; j++){
                        if(i == 0 && j == 0 && inputarr[i][j] == 1){
                                cout<<0<<endl;
                                goto oops;
                        }
                        if(i == 0 && j == 0){
                                arr[i][j] = 1;
                                continue;
                        }

                        if(inputarr[i][j] == 1) continue;

                        if( i - 1 >= 0 ){
                                arr[i][j] += arr[i-1][j];
                        }
                        if( j - 1 >= 0 ){
                                arr[i][j] += arr[i][j-1];
                        }
                }
        }


                for(int i = 0 ; i<row ; i++){
                        for(int j = 0 ; j<col ; j++){
                                cout<<arr[i][j]<<" ";
                        }
                        cout<<endl;
                }



        oops : return 0;



}

// code submitted to the leecode judge (accepted)

// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//
//         int rows = obstacleGrid.size();
//         int cols = obstacleGrid[0].size();
//
//         int arr[rows][cols];
//
//         for(int i =0 ; i<rows ; i++){
//             for(int j= 0 ; j<cols ; j++){
//                 arr[i][j] = 0;
//             }
//         }
//
//         for(int i = 0 ; i<rows; i++){
//             for(int j =0 ; j<cols ; j++){
//                 if(i == 0 && j == 0 && obstacleGrid[i][j] == 1){
//                                 goto oops;
//                 }
//                 if(i == 0 && j == 0){
//                                 arr[i][j] = 1;
//                                 continue;
//                 }
//
//                 if(obstacleGrid[i][j] == 1) continue;
//
//                 if( i - 1 >= 0 ){
//                                 arr[i][j] += arr[i-1][j];
//                 }
//                 if( j - 1 >= 0 ){
//                                 arr[i][j] += arr[i][j-1];
//                 }
//             }
//         }
//
//         oops: return arr[rows-1][cols-1];
//
//     }
// };
