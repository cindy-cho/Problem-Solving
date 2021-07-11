#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long M, N;
    int E,S;
    int ans =0 ;
    cin >> N >> M;
    vector<long long> iron(N);
    for(int i=0;i<N;i++){
        cin >> iron[i] ;
    }
    sort(iron.begin(),iron.end());
    E = N-1;
    S = 0;
    while(E>S){
        if(iron[E]+iron[S] == M){
            ans ++;
            E --;
            S ++;
        }
        else if(iron[E]+iron[S] > M){
            E--;
        }
        else if(iron[E]+iron[S] < M){
            S++;
        }
    }

    cout << ans << "\n";
    return 0;
}