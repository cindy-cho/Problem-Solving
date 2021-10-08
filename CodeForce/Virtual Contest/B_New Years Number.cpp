#include<iostream>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int n,left,div;
    while(t--){
        cin >> n;
        div = n / 2020;
        left = n % 2020;
        if(div!=0 && left==0 || div>=left) cout << "YES" <<endl;
        else cout << "NO" << endl;
    }
    return 0;
}