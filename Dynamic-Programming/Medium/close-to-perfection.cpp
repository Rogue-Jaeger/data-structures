// https://practice.geeksforgeeks.org/problems/close-to-perfection/0

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 1000000007


int main(){
        ll test , num;
        cin>>test;

        while(test--){
                cin >> num;
                //int arr[num][num];
                int val[num];

                for(int i = 0 ; i < num ; i++){
                        cin>>val[i];
                }

                int min = 0, max = 0;
                int maxval = 0; int count = 0;

                for(int i = 0 ; i < num ; i++){
                        for(int j = 0 ; j < num ; j++){
                                if(j == 0){
                                        count = 1;
                                        max = val[j];
                                        min = val[j];
                                        if( count > maxval ) maxval = count;
                                        continue;
                                }

                                if(i==j){
                                        if( val[j] < min ) min = val[j];
                                        if( val[j] > max ) max = val[j];
                                        if(max-min <= 1) count++;
                                        max = val[j];
                                        min = val[j];
                                        if( maxval < count ) maxval = count;
                                        count = 1;
                                }
                                else{
                                        if( val[j] < min ) min = val[j];
                                        if( val[j] > max ) max = val[j];
                                        if(max-min <= 1) count++;
                                        if( maxval < count ) maxval = count;
                                }

                        }
                }

                cout << maxval << endl;
        }
}



// a better approach

int main() {
        int t;
        cin>>t;
        while(t--)
        {
                int n,i,j,m1,m2,m=-1;
                cin>>n;
                int a[n+1];
                for(i=0;i<n;i++) cin>>a[i];

                for(i=0;i<n;i++)
                {
                        m1=a[i];
                        m2=a[i];
                        for(j=i+1;j<n;j++)
                        {
                                if(m2-m1>1) break;

                                if(a[j]<m1) m1=a[j];

                                if(a[j]>m2) m2=a[j];

                                if(m2-m1>1) break;

                        }
                        m=max(j-i,m);
                }
                cout<<m<<endl;
        }
        return 0;
}
