#include <bits/stdc++.h>
using namespace std;


//most optimised code for adding 2 strings see function adding

string adding(string a, string b){

        string x = "";
        int sum = 0;
        int carry = 0;

        if(a.size()<b.size()) swap(a,b);

        for(int i = 0 ; i<b.size() ; i++){
                sum = (b.at(b.size()-i-1)-'0') + (a.at(a.size()-i-1)-'0') + carry;
                carry = sum/10;
                sum = sum%10;

                x = char(sum + '0') + x; // most important see this part we have to convert int to char and add x in the end as to mimic addition
        }
        for(int i = b.size() ; i<a.size() ; i++){
                sum = (a.at(a.size()-i-1)-'0') + carry;
                carry = sum/10;
                sum = sum%10;

                x = char(sum + '0') + x;
        }
        if(carry > 0) x = char(carry + '0') + x;

        return x;
}

bool solve(string str, int startindex , int lenx ,int leny ){

        //leny>lenx ? int x = leny : int x = lenx;
        //int x = leny>lenx ? leny:lenx;//see how to write a ternary operator not as above
        //if(x > num3size) return false;


        string num1 = str.substr(startindex,lenx);//remember second argument is length of the string not ending index
        string num2 = str.substr(startindex+lenx,leny);
        string added = adding(num1,num2);

        if(str.size()-leny-lenx-startindex < added.size()) return false;

        if(added == str.substr(startindex+leny+lenx,added.size())){
                if (startindex + lenx + leny + added.size() == str.size())
                        return true;
                return solve(str,startindex+lenx,leny,added.size());
        }
        return false;
}

bool issumstr(string str){
        for(int i = 1; i<str.size() ; i++){//length of first number should start from 1
                for(int j = 1 ; j+i<str.size() ; j++){//j + i should not be equal to zero cause there is another number is there to get accomodated
                        if(solve(str,0,i,j)) return true;
                }
        }
        return false;
}


int main() {
        freopen("input.txt","r",stdin);
	int test;
        string str;
	cin>>test;
	while(test--){
	    cin>>str;
            (issumstr(str) == true) ? cout<<1<<endl : cout<<0<<endl;
        }
}
