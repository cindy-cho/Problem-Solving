#include<iostream>
#include <numeric>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    ll x,y,last;
    ll ans =0;
    cin >> x >> y;
    ans += y-x;
    last = y;
    for(int i=1;i<N;i++){
        cin >> x >> y;
        if(last<x) {
            ans += y-x;
            last = y;
        }
        else if(last>=x && last<=y) {
            ans += y-last;
            last = y;
        }
        
    }
    cout << ans << endl;
    return 0;
}