#include <bits/stdc++.h>
using namespace std;


void merge(int *arr , int start , int end , int mid){
        int numberofelements = end-start+1;                // imp
        int lptr = start;
        int rptr = mid;
        int temp[numberofelements];



        int pos = 0;
        while( lptr != mid && rptr != end+1 ){
                if( arr[lptr] < arr[rptr] ) temp[pos++] = arr[lptr++];
                else temp[pos++] = arr[rptr++];
        }
        while(lptr != mid) temp[pos++] = arr[lptr++];
        while(rptr != end+1) temp[pos++] = arr[rptr++];


        for(int i = 0 ; i < numberofelements ; i++){ // spent 4 hours on this mostimpppppppppppppppppppppppppppppppppppppppppppppppppppppppp  write here numberofelements not end
                arr[start + i] = temp[i];
        }

        return;
}



void mergesort(int *arr , int start , int end){
        if(start >= end) return;

        int mid = start + (end - start)/2;

        mergesort(arr, start, mid);
        mergesort(arr, mid+1, end);

        merge(arr , start , end , mid+1); // pehle yahan mid+1 likha tha
        return;
}



int main(){
        int arr[]={11,10,9,8,7,6,5,4,3,2,1};
        // for(int i = 0 ; i< 10 ; i++){
        //         arr[i] = 100-i;
        //         //cout << arr[i] <<endl;
        // }
        mergesort(arr, 0 , 10);
        for(int i = 0 ; i< 11 ; i++){
                cout<<arr[i]<<" ";
        }
        return 0;
}
