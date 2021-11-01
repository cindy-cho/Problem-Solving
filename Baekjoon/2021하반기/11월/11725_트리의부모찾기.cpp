#include<iostream>
#include<vector>

#define endl '\n'
typedef long long ll;

using namespace std;
vector<vector<int>> nodes(100001);
vector<int> parents(100001);
void findParent(int parent, int crnt){
    int len = nodes[crnt].size();
    parents[crnt] = parent;
    for(int i=0;i<len;i++){
        if(nodes[crnt][i]==parent) continue;
        else findParent(crnt,nodes[crnt][i]);
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N; 
    int  a,b;
    for(int i=0;i<N-1;i++){
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    int len = nodes[1].size();
    for(int i=0;i<len;i++){
        findParent(1, nodes[1][i]);
    }
    for(int i=2;i<=N;i++) cout << parents[i] << endl;
    return 0;
}