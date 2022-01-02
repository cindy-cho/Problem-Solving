#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define endl '\n'
typedef long long ll;

using namespace std;

int L,C;
vector<char> tmp;


void makePassword(int idx, string crnt, int Vow, int Con){ //모음, 자음
    if(crnt.length()==L){
        if(Vow>=1 && Con>=2){
            cout << crnt << endl;
        }
        return;
    }

    for(int i=idx+1;i<C;i++){
        if(tmp[i]=='a' || tmp[i]=='e' || tmp[i]=='i' || tmp[i]=='o' || tmp[i]=='u'){
            makePassword(i,crnt+tmp[i],Vow+1,Con);
        }
        else makePassword(i,crnt+tmp[i],Vow,Con+1);
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;
    tmp.resize(C);
    for(int i=0;i<C;i++) cin>> tmp[i];
    sort(tmp.begin(),tmp.end());
    
    makePassword(-1,"",0,0);
    
    return 0;
}