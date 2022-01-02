#include<iostream>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N,cnt=1;
    int plus = 6;
    cin >> N;
    N--;
    while(N>0){
        cnt++;
        N-=plus;
        plus+=6;
    }
    cout << cnt << endl;

    return 0;
}