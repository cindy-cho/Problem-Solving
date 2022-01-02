#include<iostream>
#include<vector>
#include<list>
#include<queue>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    int N,K;
    int X,Y,W,cur;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> N >> K;
        vector<int> time(N);
        vector<int> maxTime(N,0);
        vector<int> preBuild(N,0);
        vector<list<int>> order(N);
        list<int> :: iterator it;
        for(int j=0;j<N;j++) cin >> time[j];
        for(int j=0;j<K;j++) {
            cin >> X >> Y;
            X--; Y--;
            order[X].push_back(Y); //건물 x를 지은 다음에 y짓기 가능
            preBuild[Y]++;
        }
        cin >> W; //승리하기 위해 지어야 하는 건물 번호
        W--;
        queue<int> q;
        for(int j=0;j<N;j++){
            if(preBuild[j]==0) {
                q.push(j);
                maxTime[j] = time[j]; //건물을 짓는데 걸리는 총 시간 저장
            }
        }
        while(!q.empty()){
            cur = q.front();
            q.pop();
            
            it = order[cur].begin();
            while(it!=order[cur].end()){
                preBuild[*it]--; //지어야 하는 건물 개수 하나 삭제
            
                if(maxTime[*it] < maxTime[cur] + time[*it]){
                    maxTime[*it] = maxTime[cur] + time[*it];
            
                } //해당 건물을 짓는데 걸린는 가장 긴 시간을 maxTime에 갱신
                if(preBuild[*it]==0) {
                    q.push(*it); //0이면 queue에 넣음
            
                }
                it++;
            }
        }
        cout << maxTime[W] << endl;
    }
    return 0;
}