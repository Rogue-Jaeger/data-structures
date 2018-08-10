#include <bits/stdc++.h>
using namespace std;


int main(){
        int test;
        string str1 , str2;
        freopen("input.txt" , "r" , stdin);
        cin >> test;

        while(test--){
                cin >> str1 >> str2;
                int arr[str1.size()+1][str2.size()+1];
                int maxval = 1;
                for(int i = 0 ; i <= str1.size() ; i++){
                        for(int j = 0 ; j <= str2.size() ; j++){
                                if(i == 0 || j == 0) arr[i][j] = 0;
                                else if(str1.at(i-1) == str2.at(j-1)) arr[i][j] = arr[i-1][j-1] + 1; // this was where i was doing wrong the result should be taken from i-1,j-1 not from max i-1,j and i,j-1 + 1
                                else arr[i][j] = max(arr[i-1][j] , arr[i][j-1]);
                        }
                }
                //cout << arr[str1.size()][str2.size()] << endl;

                cout << str1.size() + str2.size() - arr[str1.size()][str2.size()] << endl;
        }
}
