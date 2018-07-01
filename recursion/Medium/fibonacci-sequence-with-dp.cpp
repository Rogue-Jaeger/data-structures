#include<iostream>
using namespace std;


long long fibonacci(long long n , long long* arr, long long num){
        if(n<2){
                arr[n] = n;
                return n;
        }

        if(arr[n] != -1) return arr[n]; //pehle se calculate ho rakhi hai iski value

        if(arr[n-1] == -1) arr[n-1] = fibonacci(n-1,arr,num);//n-1 ka calculate kar ke laao EQ1

        if(arr[n-2] == -1) arr[n-2] = fibonacci(n-2,arr,num);//n-2 ka calculate kar ke laao

        long long sum = arr[n-1] + arr[n-2];//n ka nikalo
        arr[n] = sum;//not a necessary step (can make it a comment) cause jab return hoga aur EQ1 mein jaayega to apne aap update ho jaayega cause its n-1 is current n
        for(long long i = 0; i<num ; i++) cout<<arr[i]<<" ";
        cout<<endl;
        return sum;
}

int main(){

        long long num;
        cin>>num;
        long long arr[num];

        for(long long i = 0 ; i<num ; i++) arr[i] = -1;

        long long number  = fibonacci(num-1 , arr, num);

        cout<<number<<endl;

}
