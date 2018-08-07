// https://practice.geeksforgeeks.org/problems/geek-and-its-game-of-coins/0

#include<bits/stdc++.h>
using namespace std;

// gave tle reason given
int main() {
        int t , n , x , y;
        cin>>t;

        while(t--)
        {
                cin >> n >> x >> y;

                char arr[n+1];
                int minimum = min(x,y);


                for(int i = 0 ; i < minimum ; i++){ // imp will fail if minimum > n
                        if(i%2 == 0) arr[i] = 'N';
                        else arr[i] = 'G';
                        cout<<arr[i]<<endl;
                }
                for(int i = minimum ; i <= n ; i++){
                        if(arr[i-1] == 'N') arr[i] = 'G';
                        else if(arr[i-x] == 'N') arr[i] = 'G';
                        else if(arr[i-y] == 'N') arr[i] = 'G';
                        else arr[i] = 'N';
                        cout<<arr[i]<<endl;
                }

                cout << arr[n] << endl;
        }
        return 0;
}




// right solution..................

#include <bits/stdc++.h>
using namespace std;

int main() {
        int t , n , x , y;
        cin>>t;

        while(t--)
        {
                cin >> n >> x >> y;

                char arr[n+1];

                arr[0] = 'N'; arr[1] = 'G';

                for(int i = 2 ; i <= n ; i++){
                        if(arr[i-1] == 'N') arr[i] = 'G';
                        else if(i-x>=0 && arr[i-x] == 'N') arr[i] = 'G';
                        else if(i-y>=0 && arr[i-y] == 'N') arr[i] = 'G';
                        else arr[i] = 'N';
                }

                cout << arr[n] << endl;
        }
        return 0;
}
