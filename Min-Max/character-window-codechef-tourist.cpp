// https://www.codechef.com/COOK95B/problems/GOODPERM

/**
 *    author:  tourist
 *    created: 30.06.2018 17:00:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("input.txt","r",stdin);

  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cout<<"from"<<setw(6)<<"two"<<setw(6)<<"ans"<<endl;
    cin >> n >> k;
    string s;
    cin >> s;
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != s[i + 1]) {
        int from = max(0, i - k + 1); // INCREASE AFTER VALUE 4
        int to = min(n - k - 1, i); // REMAIN CONSTANT AFTER VALUE 6
        cout<<setw(3)<<from<<setw(6)<<to<<setw(6);
        ans += to - from + 1;
        cout<<to - from + 1<<endl;
      }
    }
    cout << "answer  " << ans << '\n';
  }
  return 0;
}
