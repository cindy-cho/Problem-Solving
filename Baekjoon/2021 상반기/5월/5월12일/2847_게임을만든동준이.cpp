#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int ans =0;
    cin >> N;
    vector <int> stage(N);
    for(int i=0;i<N;i++){
        cin >> stage[i];
    }
    for(int i=N-2;i>=0;i--){
        if(stage[i] >= stage[i+1]){
            ans += stage[i] - (stage[i+1]-1);
            stage[i] = stage[i+1]-1;
        }
    }

    cout << ans << "\n";
    return 0;
}