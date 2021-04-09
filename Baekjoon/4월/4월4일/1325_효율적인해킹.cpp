#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    int i;
    int a,b,now;
    int cnt,max=0;
    queue <int> q;
    cin >> N  >> M ;
    vector < vector <int > > computer (N);
    vector < int > count (N,0);
    vector < bool > vst (N,false);
    vector < int > ans;
    for(i=0;i<M;i++){
        cin >> a >> b;
        computer[b-1].push_back(a-1);
    }
    for(i=0;i<N;i++){
        cnt =0;
        for(int j=0;j<N;j++) vst[j] = false;
        q.push(i);
        vst[i]=true;
        while(!q.empty()){
            now = q.front();
            q.pop();
            for(int j=0;j<computer[now].size();j++){
                if(vst[computer[now][j]]==false){
                    cnt++;
                    q.push(computer[now][j]);
                    vst[computer[now][j]] = true;
                }
            }
        }
        if(max < cnt) max = cnt;
        count[i] = cnt;
    }
    for(i=0;i<count.size();i++){
        if(count[i]==max){
            ans.push_back(i+1);
        }
    }

    for(auto a : ans) cout << a << " ";


    return 0;
}