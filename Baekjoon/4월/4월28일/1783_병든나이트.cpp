#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int i;
    int N, M;
    int ans=0;
    cin >> N >> M;
    if(N==1 || M==1) cout << "1\n";
    else if(M<7){
        if(N==2){
            cout << (M-1)/2+1 << "\n";
        }
        else{
            ans = min(4,M);
            cout << ans << "\n";
        }
    }
    else{
        if(N==2) cout << "4\n";
        else{
            cout << M-2 << "\n";
        }
    }
    return 0;
}