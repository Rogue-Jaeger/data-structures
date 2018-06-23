//can have equal number of ones and zeroes because ones should be strictly greater is not written there in the question
#include <iostream>
using namespace std;

void solve(string number, int ones, int remsize){//has only one variable remsize instead of calculating it from totalsize and usedspace
    if(remsize == 0){
        cout<<number<<" ";
        return;
    }

    solve(number+"1",ones+1,remsize-1);//entering one into the string

    if(ones>0) solve(number+"0",ones-1,remsize-1); //entering zero by optimising the code
}

int main() {
	int test;
	cin>>test;
	while(test--){
	    int z;
	    cin>>z;
	    solve("",0,z);////can pass a string like this
	    cout<<endl;
	}
	return 0;
}
