#include<iostream>
#include<vector>

#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin>>T;
    int N,M;
    int a,b;
    while(T--){
        cin>>N>>M;
        for(int i=0;i<M;i++){
            cin >> a >> b;
        }
        cout << N-1 << endl;
    }
    return 0;
}