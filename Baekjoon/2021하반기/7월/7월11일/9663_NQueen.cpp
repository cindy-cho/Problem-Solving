#include<iostream>
#include<vector>
#define endl '\n'
typedef long long ll;

using namespace std;
/*
퀸 이동 : 앞 뒤 옆 대각선
퀸이 서로 공격할 수 없는 조건
*/

int ans,N;

bool canGo(vector<int> chess, int x, int stage){
    for(int i=0;i<stage;i++){
        if(x== chess[i]-(stage-i) || x== chess[i]+(stage-i)) return false;
    }
    return true;
}

void nextChess(vector<int> chess, vector<bool> vst, int stage){
    if(stage==N){
        ans++;
        return;
    }
    for(int i=0;i<N;i++){
        if(vst[i]==false){
            if(canGo(chess,i,stage)==true){
                chess[stage] = i;
                vst[i] = true;
                nextChess(chess,vst,stage+1);
                chess[stage] = -1;
                vst[i] = false;
            }
        }
    }

}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    ans = 0;
    vector <int> chess(N,-1);
    vector <bool> vst(N,false);

    for(int i=0;i<N;i++){
        chess[0] = i;
        vst[i] =  true;
        nextChess(chess,vst,1);
        chess[0] = -1;
        vst[i] =  false;
    }

    cout << ans << endl;

    return 0;
}