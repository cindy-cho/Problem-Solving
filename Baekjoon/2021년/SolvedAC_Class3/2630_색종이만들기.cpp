#include<iostream>
#include<vector>
#define endl '\n'
typedef long long ll;

using namespace std;
int White, Blue;
int dir[4][2]={{0,0},{1,0},{0,1},{1,1}};
vector<vector<int>> paper;
void isColored(int N,int x, int y){
    if(N==0) return;
    bool whiteFlag = false, blueFlag = false;
    for(int i=x;i<x+N;i++){
        for(int j=y;j<y+N;j++){
            if(paper[i][j]==0) whiteFlag = true;
            else blueFlag = true;
        }
    }
    if(whiteFlag == false && blueFlag == true) Blue++; // if there are only blue papers
    else if(whiteFlag == true && blueFlag == false) White ++; // if there are only whites
    else{
        N /= 2;
        for(int i=0;i<4;i++){
            isColored(N, x+dir[i][0]*N,y+dir[i][1]*N);
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    paper.resize(N,vector<int> (N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cin >> paper[i][j];
    }
    // white : 0, blue : 1
    White = 0;
    Blue = 0;
    isColored(N,0,0);
    cout << White << endl << Blue << endl;
    return 0;
}