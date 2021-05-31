#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<int,int>> person(N);
    vector<int> ans(N,1);
    for(int i=0;i<N;i++){
        cin >> person[i].first >> person[i].second ;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if (i==j) continue;
            if(person[i].first < person[j].first && person[i].second < person[j].second) ans[i]++;
        }
    }
    for(int i=0;i<N;i++) cout << ans[i] << " ";
    return 0;
}