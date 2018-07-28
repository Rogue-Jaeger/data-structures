#include <bits/stdc++.h>
using namespace std;


void swap(char* str , int start , int a){
        char temp = str[start];
        str[start] = str[a];
        str[a] = temp;
        return;


}

void permute(char * str , int len ,int start = 0){
        if(start == len){
                // printf("%s" , str);
                // cout<<endl;
                cout<<"chala "<<endl;
                return;
        }
        for(int a = start ; a<len ; a++){
                printf("first %s \n" , str);
                swap(str , start , a);
                printf("second %s \n" , str);
                permute(str , len , start+1);
                printf("third %s \n" , str);
                swap(str , start , a);
                printf("fourth %s \n" , str);
        }
        return;
}

int main(){
        char arr[] = "ABC";
        permute(arr , 3);
        return 0;
}
