#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M,A,B,idx1,idx2,sum=5500,nowSum;
    cin >> N >> M;
    vector<list<int>> MAP(N+1);
    vector<vector<int>> TIME(N+1, vector<int> (N+1,0));
    vector<bool> vst(N+1,false);
    queue <pair<int,int>> q;
    pair<int,int> tt;
    list<int>::iterator iter;
    
    for(int i=0;i<M;i++){
        cin >> A >> B;
        MAP[A].push_back(B);
        MAP[B].push_back(A);
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++) vst[j]=false;
        q.push({i,0});
        vst[i]=true;
        while(!q.empty()){
            tt = q.front();
            q.pop();
            TIME[i][tt.first]= tt.second;
            iter = MAP[tt.first].begin();
            for(;iter!=MAP[tt.first].end();iter++){
                if(vst[*iter]==false){
                    vst[*iter]=true;
                    q.push({*iter,tt.second+1});
                }
            }
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            nowSum=0;
            if(i==j) continue;
            for(int k=1;k<=N;k++){
                nowSum+= min(TIME[i][k],TIME[j][k]);
            }
            if(nowSum < sum){
                sum = nowSum;
                idx1=i;
                idx2=j;
            }
        }
    }

    cout << idx1 << " " << idx2 << " " << sum*2 << "\n";
    return 0;
}