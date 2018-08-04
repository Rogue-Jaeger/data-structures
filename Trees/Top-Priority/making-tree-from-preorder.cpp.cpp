#include<bits/stdc++.h>
using namespace std;


int solve(char str[], int index, int h, int &maxh, int size){
        if(str[index] == 'l' || index == size)
        {
                if(h > maxh)
                {
                        maxh = h;
                }
                return index;
        }
        int left = solve(str, index+1, h+1, maxh, size);
        int right = solve(str, left+1, h+1, maxh, size); // immmmmppppp if left is returning something right should also return the jist of the same thing

        return right;
}


int depth(char str[]) {
        int size =  strlen(str);
        cout<<size<<endl;
        int maxh = 0;
        solve(str , 0 , 0 , maxh , size);
        return maxh;
}


int main(){
        char str[] = "nlnll";
        int d = depth(str);
        cout << d << endl;
}
