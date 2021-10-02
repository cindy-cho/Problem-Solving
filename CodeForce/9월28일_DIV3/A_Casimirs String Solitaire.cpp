#include<iostream>
#include<string>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int tc;
    int A,B,C,sLen;
    cin >> tc;
    for(int t=0;t<tc;t++){
        cin >> s;
        A=0;
        B=0;
        C=0;
        sLen = s.length();
        for(int i=0;i<sLen;i++){
            if(s[i]=='A') A++;
            else if(s[i]=='B') B++;
            else if(s[i]=='C') C++;
        }
        if(B==A+C) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}