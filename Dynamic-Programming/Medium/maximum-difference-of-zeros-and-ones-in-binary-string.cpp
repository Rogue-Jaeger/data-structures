// https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string/0

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 1000000007


int main(){
        ll test; string str;
        cin>>test;

        while(test--){
                cin >> str;
                int count1 = 0 , count0 = 0 , maxcount = 0;

                for(int i = 0 ; i < str.size() ; i++){

                        if( str.at(i) == '1' ) count1++;
                        else count0++;

                        if( count0-count1 <= 0 ){
                                count0 = 0; count1 = 0;
                        }
                        else{
                                if(maxcount < count0-count1) maxcount = count0-count1;
                        }
                }
                if(maxcount>0) cout << maxcount << endl;
                else cout << -1 << endl;
        }
}
