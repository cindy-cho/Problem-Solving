#include<iostream>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int E, S, M;
    int ans=1;
    cin >> E >> S >> M;
    // 15, 28, 19
    for(;;ans++){
        if((ans-E)%15==0 && (ans-S)%28==0 && (ans-M)%19==0){
            cout << ans << endl;
            break;
        }
    }
    return 0;
}