#include<iostream>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int len;
    string hexInt;
    int ANS=0,hex=1;
    cin>> hexInt;
    len = hexInt.length();
    for(int i=len-1;i>=0;i--){
        if(hexInt[i]>='0' && hexInt[i]<='9') ANS += (hexInt[i]-'0') * hex;
        else ANS += (hexInt[i]-'A'+10)*hex;
        hex *=16;
    }
    cout << ANS << "\n";
    return 0;
}