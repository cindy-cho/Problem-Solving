#include<iostream>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int L,P,V;
    int tc = 1;
    int ans;
    // 연속하는 P일 중 L일 동안 사용할 수 있다. 강산이는 V일짜리 휴가를 시작했다.
    // 1 < L < P < V

    while(1){
        cin >> L >> P >> V;
        if(L==0 && P==0 && V==0) break;
        ans = 0;
        ans = (V/P)* L;
        V%P <= L ? ans+=V%P : ans+=L;
        cout << "Case " << tc << ": " << ans << endl;
        tc ++; 
    }
    return 0;
}