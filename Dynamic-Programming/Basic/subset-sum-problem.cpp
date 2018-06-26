#include<iostream>
#include<iomanip>
using namespace std;

int main(){
        freopen("input.txt" , "r" , stdin);
        int num,sum;
        cin>>num>>sum;


        int basic[num];
        bool arr[sum+1][num+1];

        for(int i = 0 ; i<num ; i++){
                cin>>basic[i];
        }

        for(int i = 0; i<=sum ; i++){
                for(int j = 0 ; j<=num ; j++){
                        if(i == 0 && j!=0){
                                arr[i][j] = true;
                                continue;
                        }
                        if(j == 0 && i!=0){
                                arr[i][j] = false;
                                continue;
                        }
                        if(i == 0){
                                arr[i][j] = true;
                                continue;
                        }

                        arr[i][j] = arr[i][j-1]; //by default previous in the row

                        if( i >= basic[j-1] ) arr[i][j] = arr[i][j] || arr[i-basic[j-1]][j-1]; /*chance given to current cell to become true
                        by default if it is declared false due to previous element in the row of matrix*/
                }

        }

        //code to print the numbers leading upto the sum

        // if(arr[sum][num] == true){
        //         while(sum && num){                                          //num and sum should not be equal to 0
        //                 while(arr[sum][num] == arr[sum][num-1]) num--;
        //                 cout<<basic[num-1]<<" ";
        //                 sum -= basic[num-1];
        //                 num--;
        //         }
        // }
        // else cout<<"NO";
        //cout<<endl;

        cout<<"       * ";
        for(int i = 0 ; i<num ; i++){
                cout<<setw(4)<<basic[i]<<" "; //here iomanip is used
        }
        cout<<endl;

        for(int i = 0 ; i<=sum ; i++){
                cout<<i<<"   ";
                for(int j = 0; j<=num ; j++){
                        cout<<setw(4)<<arr[i][j]<<" ";
                }
                cout<<endl;
        }

        (arr[sum][num]) ? cout<<"TRUE"<<endl : cout<<"FALSE"<<endl;

}
