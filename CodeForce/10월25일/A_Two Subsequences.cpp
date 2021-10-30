#include<iostream>
#include <string>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    string S;
    int Slen;
    int i;
    char prefix;
    while(tc--){
        cin >> S;
        Slen = S.length();
        prefix = 'z';
        for(i=0;i<Slen;i++) if(S[i] < prefix ) prefix = S[i];
        for(i=0;i<Slen;i++) if(S[i] == prefix) break;
        if(i==0){
            cout << prefix << " " << S.substr(1,Slen-1) << endl;
        }
        else if(i==Slen-1){
            cout << prefix << " " << S.substr(0,Slen-1) << endl;
        }
        else{
            cout << prefix << " " << S.substr(0,i)+S.substr(i+1,Slen-i) << endl;
        }
        
    }
    return 0;
}