#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<map>
#define endl '\n'
typedef long long ll;

using namespace std;

struct comp{
    bool operator()(pair<string,int> A , pair<string,int> B){
        if(A.second==B.second){
            return A.first > B.first;
        }
        return A.second > B.second;
    }
};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    string A,B;
    map<string,int> itemIdx;
    
    
    pair<int,int> cur;
    queue<pair<int,int>> q;
    priority_queue<pair<string,int>,vector<pair<string,int>>, comp> ans;
    int idx=0;
    int depth = 0;

    cin >> N;
    vector<string> idxItem(N*2);
    vector<int> total(2*N,0);
    vector<list<int>> order(2*N);
    list<int>::iterator it;
    for(int i=0;i<N;i++){
        cin >> A >> B;
        if(itemIdx.find(A)==itemIdx.end()) {
            idxItem[idx] = A;
            itemIdx[A] = idx++;
        }
        if(itemIdx.find(B)==itemIdx.end()) {
            idxItem[idx] = B;
            itemIdx[B] = idx++;
        }
        order[itemIdx[A]].push_back(itemIdx[B]);
        total[itemIdx[B]]++;
    }
    for(int i=0;i<idx;i++){
        if(total[i]==0){
            q.push({i,depth});
        }
    }
    while(!q.empty()){
        cur = q.front();
        ans.push({idxItem[cur.first],cur.second});
        q.pop();
        for(it = order[cur.first].begin() ; it!=order[cur.first].end(); it++){
            total[*it] --;
            if(total[*it]==0){
                q.push({*it,cur.second+1});
            }
        }
    }
    for(int i=0;i<idx;i++) if(total[i]!=0){
        cout << "-1" << endl;
        return 0;
    }
    while(!ans.empty()){
        cout << ans.top().first << endl;
        ans.pop();
    }
    return 0;
}