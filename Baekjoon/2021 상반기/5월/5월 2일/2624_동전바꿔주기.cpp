#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> A, pair<int,int> B){
    if(A.first > B.first) return true;
    return false;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    long long unsigned ANS;
    int K;
    int count;
    ANS = 0;
    cin >> T >> K;
    vector<pair<int,int>> COIN (K);
    vector<long long unsigned> DP(T+1,0);

    for(int i=0;i<K;i++){
        cin >> COIN[i].first >> COIN[i].second ;
    }
    sort(COIN.begin(),COIN.end(),cmp);

    for(int i=1;i<=COIN[0].second;i++){
        if(i*COIN[0].first<=T) DP[i*COIN[0].first]=1;
    }

    for(int i=1;i<K;i++){
        for(int j=T;j>=COIN[i].first;j--){
            count = 0;
            for(int p=1;p<=COIN[i].second;p++){
                if(j-p*COIN[i].first>=0) count+=DP[j-p*COIN[i].first];
            }
            DP[j] = DP[j] + count;
            if(j%COIN[i].first==0 && j/COIN[i].first<=COIN[i].second) DP[j]++;
        }
    }


    cout << DP[T] << "\n";
    return 0;
}