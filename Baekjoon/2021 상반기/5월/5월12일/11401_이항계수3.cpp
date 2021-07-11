#include<iostream>

using namespace std;
#define mod 1000000007
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long N,K,top=1,btm=1;
    cin >> N >> K;
    if(K==0 || K==N){
        cout << "1\n";
        return 0;
    }
    if(N-K < K) K = N-K;

    for(int i=N;i>=(K+1);i--){
        top = (top * i) % mod;
        btm = (btm * (i-K)) % mod;
    }
    top = (top/btm)%mod;
    cout << top << "\n";
    return 0;
}