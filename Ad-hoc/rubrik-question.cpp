#include <bits/stdc++.h>
using namespace std;

int sum(int i){
        int sum = 0;
        while(i != 0){
                sum += i%10;
                i /= 10;
        }
        return sum;
}

int main(){
        int num = 100000;
        vector <double> v;
        vector <int> result;

        for(int i = 1 ; i <= num ; i++) v.push_back( double ( i * 1.0 / sum(i) ) );
        for(int i = 0 ; i < num ; i++){
                bool temp = true;
                for(int j = i+1 ; j < num ; j++){
                        if( v[i] > v[j] ){ temp = false; break; }
                }
                if(temp) result.push_back(i+1);
        }

        for(int i = 0 ; i< result.size() ; i++) cout << result[i] << endl;

}
