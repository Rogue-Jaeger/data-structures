#include<bits/stdc++.h>
using namespace std;

// gave tle
int main() {
        int t;
        string str1 , str2;
        cin>>t;

        while(t--)
        {
                cin >> str1;
                str2 = "";
                for(int i = str1.size()-1 ; i>=0 ; i--) str2 += str1.at(i);
                int dp[str1.size()+1][str1.size()+1];

                cout<<"    ";
                for(int i = 0 ; i< str1.size() ; i++){
                        cout<<str1.at(i)<<" ";
                }cout<<endl;

                for(int i = 0 ; i<=str1.size() ; i++){
                        if(i-1>=0) cout<<str2.at(i-1)<<" ";
                        for(int j = 0 ; j<=str1.size() ; j++){
                                if(!i||!j){
                                        dp[i][j] = 0;cout<<"0 ";
                                        continue;
                                }

                                if( str1.at(i-1) == str2.at(j-1) ) dp[i][j] = 1+dp[i-1][j-1];
                                else dp[i][j] = max( dp[i][j-1] , dp[i-1][j] );
                                cout<<dp[i][j]<<" ";
                        }cout<<endl;
                }
                cout << str1.size() - dp[str1.size()][str1.size()] << endl;
        }//cout<<str1.at(1)<<" "<<str2.at(1)<<endl;
        return 0;
}
