#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M,K;
    int count=0;
    cin >> N >> M >> K;
    int a;
    double sum=0;
    double s;
    pair<double,int> cur;
    priority_queue <pair<double,int>> singing;
    vector<int> vst(N,0);
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin >> a >> s;
            a--;
            singing.push({s,a});
        }
    }
    while(count<K){
        cur = singing.top();
        if(vst[cur.second]==0){
            sum += cur.first;
            vst[cur.second]=1;
            count++;
        }
        singing.pop();
    }
    printf("%.1f\n",sum);
    return 0;
}

