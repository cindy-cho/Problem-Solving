#include<iostream>
#include<vector>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    ll n,x,p,pb;
    bool isSorted;
    cin >> tc;
    while(tc--){
        cin >> n >> x;   
        pb = 0;
        isSorted = true;
        for(int i=0;i<n;i++){
            cin >> p;
            if(p < pb) isSorted=false;
            pb = p;
        }
        if(isSorted==true) cout << "YES\n";
        else{
            if(n<=x) cout << "NO\n";
            else{
                cout << "YES\n";
            }
        }
    }
    return 0;
}