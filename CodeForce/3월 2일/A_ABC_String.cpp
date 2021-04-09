#include<iostream>
#include<string>

using namespace std;

int consider(string input,int A, int B, int C){
    int i,sum=0;
    for(i=0;i<input.length();i++){
        if(input[i]=='A') sum+=A;
        else if(input[i]=='B') sum+=B;
        else if(input[i]=='C') sum+=C;

        if(sum<0) return -1; 
    }

    if(sum==0) return 1;
    else return -1;
}

int main(void){
    int t,i;
    int A=0,B=0,C=0,sum=0,resA,resB,resC;
    string input;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        A=0;
        B=0;
        C=0;
        sum=0;

        cin >> input;
        
        if(input[0]=='A'){
            resA=consider(input,1,-1,1);
            resB=consider(input,1,1,-1);
            resC=consider(input,1,-1,-1);
        }

        else if(input[0]=='B'){
            resA=consider(input,-1,1,1);
            resB=consider(input,1,1,-1);
            resC=consider(input,-1,1,-1);
        }

        else if(input[0]=='C'){
            resA=consider(input,1,-1,1);
            resB=consider(input,-1,1,1);
            resC=consider(input,-1,-1,1);
        }

        if(resA==1 || resB==1 || resC==1) cout << "YES" <<endl;
        else cout << "NO" << endl;
    }
    return 0;
}