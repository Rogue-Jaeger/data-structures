#include <bits/stdc++.h>
using namespace std;



int solve(string str1 , string str2 , int index1 , int index2 , vector< vector <int> > & arr ){
        if(index1 == str1.size() || index2 == str2.size()) return 0;

        if(arr[index1][index2] != -1) return arr[index1][index2];

        if(str1.at(index1) == str2.at(index2)){
                arr[index1][index2] = 1 + solve(str1 , str2 , index1+1 , index2+1 , arr);
                return 1 + solve(str1 , str2 , index1+1 , index2+1 , arr);
        }
        else{
                arr[index1][index2] = max(solve(str1 , str2 , index1+1 , index2 , arr) , solve(str1 , str2 , index1 , index2+1 , arr));
                return max(solve(str1 , str2 , index1+1 , index2 , arr) , solve(str1 , str2 , index1 , index2+1 , arr));
        }
}

int main(){
        string str1 = "faudcvaiubfiuabiufsjdjfaihsdafgvdafvkidonhfovasadeobvfiahnde";
        string str2 = "faauvciouasbdvubaisubfdvjasbudfhcuhkhjdfgoiushaeyuvfbiaiasu";

        vector<vector <int> > arr;
        vector <int > helper;
        for(int i = 0 ; i < str1.size() ; i++){
                for(int j = 0 ; j < str2.size() ; j++){
                        helper.push_back(-1);
                }
                arr.push_back(helper);
        }



        cout << str1.size() << " " << str2.size() << endl;
        cout << solve(str1 , str2 ,0 , 0 , arr) << endl;

        for(int i = 0 ; i < str1.size() ; i++){
                for(int j = 0 ; j < str2.size() ; j++){
                        cout << arr[i][j] << " ";
                }
                cout << endl;
        }
}
