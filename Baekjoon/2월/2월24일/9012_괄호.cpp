#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void){
    int N,i,j,value;
    string input;

    scanf("%d\n",&N);
    for(i=0;i<N;i++){
        
        value=0;
        getline(cin,input);
        for(j=0;j<input.length();j++) {
            
            if(input[j]=='(') value ++;
            else value--;
            if(value <0){
                value = 1;
                break;
            }
        }
        if(value==0) printf("YES\n");
        else printf("NO\n");
        
    }
}