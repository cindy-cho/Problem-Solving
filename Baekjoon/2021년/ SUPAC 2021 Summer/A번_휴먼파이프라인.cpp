#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int N,idx=1;
    ll max=0, crnt=0;
    ll K;
    cin >> N >> K;
    vector<ll> speed(N);
    for(int i=0;i<N;i++){
        cin >> speed[i]; 
    }
    sort(speed.begin(),speed.end());
    for(;idx<N;idx++){
        crnt = ( speed[0] * idx ) + ( speed[idx] * (N-idx)) ;
        if(crnt > max) max = crnt;
    }
    if( K % max == 0) cout << K/max << endl;
    else cout << K/max+1 << endl;
    return 0;
}