#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    int u,v,idx;
    double answer,mini=1000000001;
    double value[100001][2];
    list<int> edge[100001];
    list<int> :: iterator it;
    queue <int> q;
    int cur;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        answer = 0;
        for(int j=1;j<=n;j++){
            cin >> value[j][0] >> value[j][1];
            if(value[j][0] > value[j][1]) swap(value[j][0], value[j][1]);
            if(value[j][0]<mini){
                mini = value[j][0];
                idx = j;
            }
        }
        for(int j=0;j<n-1;j++){
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        q.push(idx);
        while(!q.empty()){
            cur=q.front();
            q.pop();
        }
    }
    return 0;
}