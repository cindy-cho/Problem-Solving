#include<iostream>
#include<vector>
#include<math.h>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    bool flag;
    ll n;
    cin >> t;
    while(t--){
        cin >> n; 
        while(n%2==0){
            n/=2;
        }
        n == 1 ? cout << "NO" << endl : cout << "YES" << endl;
    }
    return 0;
}