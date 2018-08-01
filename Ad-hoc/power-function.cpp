#include <bits/stdc++.h>
using namespace std;

int power( int num , int pow ){
        if( pow == 0 ) return 1;

        if( pow%2 == 1 ){
                int i = power(num , pow/2) * power(num , pow/2) * num;
                cout << "odd   " << i << endl;
                return i;
        }
        else{
                int i = power(num , pow/2) * power(num , pow/2);
                cout << "even   " << i << endl;
                return i;
        }
}

int main(){
        cout << power(5 , 8) << endl;
}
