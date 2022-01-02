#include<iostream>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string OCT,BIN="";
    string arr[8]={"000","001","010","011","100","101","110","111"};
    cin >> OCT;
    if(OCT=="0"){
        cout << "0\n";
        return 0;
    }
    int i, len = OCT.length();
    for(i=0;i<len;i++){
        BIN += arr[OCT[i]-'0'];
    }
    len = BIN.length();
    for(i=0;i<len;i++){
        if(BIN[i]=='1') break;
    }
    BIN = BIN.substr(i,len-i);
    cout << BIN << "\n";
    return 0;
}