#include <bits/stdc++.h>
using namespace std;

// wrong sol a case that fails this is aaaaaa the sol is 4

int solve(string old , int &count){
        string str = old.substr(0 , 1);
        count++;
        int max = 0;

        for(int i = 1 ; i < old.size() ; i++){
                count++;
                str += old.at(i);
                if(str.size()%2 == 0){
                        if( str.substr(0 , str.size()/2) == str.substr(str.size()/2 , str.size()/2) ) if(i > max) max = i;
                }
        }

        while(max%2 == 1){
                if( old.substr( 0 , (max+1)/2) == old.substr( (max+1)/2 , (max+1)/2 ) ){
                        count = count - (max+1)/2 + 1;
                }
                max = max/2;
        }
        //count = count - (max+1)/2 + 1;
        return count;

}

int main(){
        int test;
        cin>>test;

        while(test--){
                string str;
                cin>>str;
                int count = 0;
                int res = solve(str , count);
                cout<<res<<endl;
        }
}
