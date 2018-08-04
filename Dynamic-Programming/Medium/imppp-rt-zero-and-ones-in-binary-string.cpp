#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 1000000007


// void solve(vector <ll> & dp, ll index , ll num){
//         if(index>num) return;

//         for(ll i = 0; i < index/2; i++){
//                 dp[index] += dp[i]*dp[index-1-i]*2;
//                 dp[index] %= M;
//         }
//         if(index%2 == 1) dp[index] += dp[index/2] * dp[index/2];
//         dp[index] %= M;

//         solve(dp , index+1 , num);
// }

int main(){
        ll test , num , res;
        cin>>test;

        while(test--){
                cin>>num;
                vector <ll> dp(num+1, 0);
                dp[0] = 1; dp[1] = 1;

                if(num<=1){
                        cout<<dp[num]<<endl;
                        continue;
                }

                for(ll i = 2 ; i <= num ; i++){

                    for(ll j = 0; j < i/2; j++){
                        dp[i] += dp[j] * dp[i-1-j] * 2;
                        dp[i] %= M;
                    }
                    if(i%2 == 1) dp[i] += dp[i/2] * dp[i/2];
                    dp[i] %= M;
                }

                cout<<dp[num]<<endl;
        }
}




// other's sol he has calculated catalan number previously thats why i was given tle..........

#define mod 1000000007
using namespace std;
int main()
{
	long long int i,j,t,n;
	long long int catalan[1001];
	catalan[0]=1;
	catalan[1]=1;
	for(i=2;i<=1000;i++)
	{
		catalan[i]=0;
		for(j=0;j<i;j++)
		{
			catalan[i]=(catalan[i]%mod+(catalan[j]%mod*catalan[i-j-1]%mod)%mod)%mod;
		}
	}
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << catalan[n] << endl;
	}
}
