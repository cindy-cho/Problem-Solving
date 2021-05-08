#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

#define INF 2100000000

struct compare{
    bool operator()(pair<int,int> A, pair<int,int> B){
        return A.second > B.second;
    }
};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int V,E,K;
    cin >> V >> E;
    cin >> K;
    K--;
    int s,e,w;
    pair<int,int> cur;
    list<pair<int,int>> graph[20000];
    // vector<list <pair<int,int>>> graph(V);
    vector<long long> min(V, INF);
    priority_queue <pair<int,int>, vector<pair<int,int>>, compare> pq;
    for(int i=0;i<E;i++){
        cin >> s >> e >> w;
        s--;
        e--;
        graph[s].push_back({e,w});
    }
    min[K]=0;
    pq.push({K,0});
    list<pair<int,int>>::iterator it;
    while(!pq.empty()){
        cur = pq.top();
        pq.pop();
        // cout << cur.first << "," << cur.second << endl;
        if(cur.second > min[cur.first]) continue;
        else{
            it = graph[cur.first].begin();
            while(it!=graph[cur.first].end()){
                if(min[(*it).first] > min[cur.first]+(*it).second){
                    min[(*it).first] = min[cur.first] + (*it).second;
                    pq.push({(*it).first,min[(*it).first]});
                }
                it++;
            }
        }
    }

    for(int i=0;i<V;i++){
        if(min[i]==INF) cout << "INF\n";
        else cout << min[i] << "\n";
    }
    return 0;
}