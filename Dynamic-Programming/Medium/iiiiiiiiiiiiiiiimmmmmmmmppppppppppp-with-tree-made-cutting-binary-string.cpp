// https://practice.geeksforgeeks.org/problems/cutting-binary-string/0

#include<bits/stdc++.h>
using namespace std;


     tree for  1011

                                        1011
                                        /    \
                                statement 2    \
                                violated          \
                                cause                \
                                s[i+1]!=1                \
                                                            val = 1
                                                            count = 1
                                                            binaryleft = 011
                                                            /                 \
                                                         /                        \
                                                       /                              \
                                                    statement 2                            \
                                                    will not work                            val = 5
                                                    cause                                    binaryleft = 1
                                                    val here is 2                            count = 1
                                                                                          /                     \
                                                                                        /                        \
                                                                                statement 2                       count = 2
                                                                                will                                     end of loop
                                                                                work
                                                                                count = 3
                                                                                and end of loop
bool power5(long long int val)
{
        if(val<5)
        {
                return false;
        }
        while(val != 0)
        {
                if(val%5 == 0 || val == 1)
                {
                        val /= 5;
                }
                else
                {
                        return false;
                }
        }
        return true;
}

void solve(string s, int i, int &ans, int count, long long int val)
{


        int n = s.size();

        val *= 2;  // calculating the binary value of the number
        if(i<n && s[i] == '1')   val += 1;  // calculating the binary value of the number


        //cout<<val<<" ";


        if(i == n-1 )
        {
                if(power5(val) || val == 1) ans = min(ans,count);
                cout<<ans<<" ";
                return;
        }

        /*statement - 1*/if((val == 1 || power5(val)) && i<n-1 && s[i+1] == '1')  solve(s,i+1,ans,count+1,0);

        /*statement - 2*/solve(s,i+1,ans,count,val);
}

int main()
{
        ///*
        int t;
        cin>>t;
        string s;

        while(t--)
        {
                cin>>s;
                int ans = INT_MAX;
                if(s.size() == 0 || (s.size() ==1 && s[0] == '1'))
                        cout<<"1"<<endl;
                else if(s[0] == '0')
                        cout<<"-1"<<endl;
                else
                {
                        solve(s,0,ans,1,0);
                        if(ans == INT_MAX) cout<<"-1"<<endl;
                        else cout<<ans<<endl;
                }
        }
        //*/
        return 0;
}
