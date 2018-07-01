#include<iostream>
#include<limits>
#include<iomanip>
using namespace std;

// HERE THE COMPLEXITY IS N*2 BUT SPACE REQUIRED IS N


int main(){
        freopen("input.txt" , "r" , stdin);

        int num;
        int sum;

        cin>>num>>sum;

        int basic[num],arr[sum+1];

        for(int i = 0 ; i<num ; i++){
                cin>>basic[i];
        }


        for(int i = 1 ; i<=sum ; i++) arr[i] = INT_MAX-1;
        arr[0] = 0;

        for(int i = 1; i<= sum ; i++){
                for(int j = 0 ; j < num ; j++){
                        if( i >= basic[j] ){ // if the number array (given to us) has less value than a particular sum enter
                                //cout<<i<<" "<<arr[i]<<" "<<arr[i-basic[j]] + 1<<endl;
                                if(arr[i] > arr[i-basic[j]] + 1/* HERE WE ARE ADDING 1 INT TO INT MAX SO IT WILL OVERFLOW THATS WHY INT_MAX-1 WAS DONE ABOVE*/)  arr[i] = arr[i-basic[j]] + 1; // if there is a value already in the particular position in that array which we are making comparing if the current value we are going to enter is less than current value going to be entered
                        }
                }
        }

        for(int i = 0 ; i<= sum ; i++) cout<<setw(3)<<i<<" ";
        cout<<endl;
        for(int i = 0 ; i<= sum ; i++) cout<<setw(3)<<arr[i]<<" ";
        cout<<endl;
}
