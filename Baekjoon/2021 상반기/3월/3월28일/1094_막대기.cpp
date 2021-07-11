#include<iostream>
#include<string>

using namespace std;

int main(void){
    int X,stick=64;
    int ans=0,count=0;
    int i,idx;
    string n="";
    string tmp;
    cin >> X;
    while(X>0){
        if(X%2==1) tmp='1';
        else tmp = '0';
        n = tmp + n;
        X=X/2;
    }

  
    for(i=n.length()-1;i>=0;i--){
        if(n[i]=='1') ans++;
    }

    cout << ans << endl;
    return 0;
}