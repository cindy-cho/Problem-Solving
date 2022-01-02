#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M,close,ans=0;
    cin >> N >> M;
    vector<int> card(N);
    for(int i=0;i<N;i++) cin >> card[i];
    sort(card.begin(),card.end());
    for(int i=0;i<N-2;i++){
        if(card[i]>M) continue;
        for(int j=i+1;j<N-1;j++){
            if(card[i]+card[j]>M) continue;
            for(int k=j+1;k<N;k++){
                if(card[i]+card[j]+card[k]<=M && card[i]+card[j]+card[k]>ans){
                    ans = card[i]+card[j]+card[k];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}