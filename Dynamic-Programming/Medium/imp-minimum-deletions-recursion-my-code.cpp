#include<bits/stdc++.h>
using namespace std;

// memoise it and never make a new string (reverse of given)

int solve(string str1 , int index1 , int index2){
        if(index1 >= index2){
                return 0;
        }

        int left = 0 , right = 0;

        if(str1.at(index1) == str1.at(index2)){
                left = solve( str1 ,  index1+1 , index2-1 );
        }
        else{
                right = min ( solve( str1 , index1+1 , index2) , solve(str1 , index1 , index2-1) ) + 1;
        }

        return left + right;
}


int main() {
        int t;
        string str1 , str2;
        cin>>t;

        while(t--)
        {
                cin >> str1;
                cout << solve(str1 ,  0 , str1.size()-1)  << endl;
        }
        return 0;
}
