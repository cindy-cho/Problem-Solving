#include <string>
#include <vector>
#include<iostream>
using namespace std;

typedef struct{
    int isColumn;
    int isGirder;
}pos;
bool installColumn(int,int,int,int,vector<vector<pos>>);
bool installGirder(int,int,int,int,vector<vector<pos>>);

bool installColumn(int n,int flag, int x, int y, vector<vector<pos>> ground){ //기둥
    // flag == 0 : 삭제 , 1 : 설치, 2 : 체크
    if(flag==1 || flag==2) {
        if(x==n || ((y-1)>=0 && ground[x][y-1].isGirder==1) || (ground[x][y].isGirder==1) || ((x+1)<=n && ground[x+1][y].isColumn==1)) return true;
        else return false;
    }

    ground[x][y].isColumn=0;        
    if(x-1>=0){
        //위쪽 기둥 체크{
        if(ground[x-1][y].isColumn==1){
            if(installColumn(n,2,x-1,y,ground)==false) return  false;
        }
        
        //위에 보 체크
        if(ground[x-1][y].isGirder==1){
            if(installGirder(n,2,x-1,y,ground)==false) return false;
        }
        
        //왼쪽 위 보 체크
        if(y-1>=0){
            if(ground[x-1][y-1].isGirder==1){
                if(installGirder(n,2,x-1,y-1,ground)==false) return false;
            }
        }
    }

    return true;
}
bool installGirder(int n,int flag, int x, int y, vector<vector<pos>> ground){ //보
    // flag == 0 : 삭제 , 1 : 설치, 2 : 체크
    if(flag==1 || flag==2){
        if( ( (x+1)<=n && ground[x+1][y].isColumn==1) || ( (y+1) <=n && (x+1)<=n && ground[x+1][y+1].isColumn==1 ) || ( (y-1) >=0 && (y+1)<=n && ground[x][y-1].isGirder==1 && ground[x][y+1].isGirder==1)) return true;
        else return false;
    }
    
    if(flag==0) ground[x][y].isGirder=0;

    //위 기둥 체크
    if(ground[x][y].isColumn==1 && installColumn(n,2,x,y,ground)==false) return false;
    //왼쪽 보 체크
    if((y-1)>=0){
        if(ground[x][y-1].isGirder==1 && installGirder(n,2,x,y-1,ground)==false) return false;
    }
    if((y+1<=n)){
        //오른쪽 보 체크
        if(ground[x][y+1].isGirder==1 && installGirder(n,2,x,y+1,ground)==false) return false;
        //오른쪽 위 기둥 체크
        if(ground[x][y+1].isColumn==1 && installColumn(n,2,x,y+1,ground)==false) return false;
    }   

    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<vector<pos>> ground(n+1,vector<pos> (n+1));
    int buildSize = build_frame.size();
    int x,y;
    // build_frame = [x, y, 구조물의 종류, 설치삭제]
    // 0,1 = 기둥, 보
    // 0,1 - 삭제, 설치

    // x,y좌표 전환 : (n-y, x)

    //맵 초기화
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            ground[i][j].isColumn=0;
            ground[i][j].isGirder=0;
        }
    }

    // 설치 수행
    for(int i=0;i<buildSize;i++){
        // for(int k=0;k<n+1;k++){
        //     for(int j=0;j<n+1;j++){
        //         if(ground[k][j].isColumn==1 && ground[k][j].isGirder==1) cout << 3 << " ";
        //         else if(ground[k][j].isColumn==1) cout << 1 << " ";
        //         else if(ground[k][j].isGirder==1) cout << 2 << " ";
        //         else cout << "0 ";
        //     }
        //     cout << endl;
        // }
        // cout << "-----------\n";
        x = n-build_frame[i][1];
        y = build_frame[i][0];
        if(build_frame[i][3]==0){ // 구조물 삭제
            if(build_frame[i][2]==0) {
                if(installColumn(n,0,x,y,ground)==false) continue;
                ground[x][y].isColumn=0;
            }
            else if(build_frame[i][2]==1)  {
                if(installGirder(n,0,x,y,ground)==false) continue;
                ground[x][y].isGirder=0;
            }
        }
        else if(build_frame[i][3]==1){ // 구조물 설치
            if(build_frame[i][2]==0) {
                if(installColumn(n,1,x,y,ground)==false) continue;
                ground[x][y].isColumn=1;
            }
            else if(build_frame[i][2]==1)  {
                if(installGirder(n,1,x,y,ground)==false) continue;
                ground[x][y].isGirder=1;
            }
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=n;j>=0;j--){
            if(ground[j][i].isColumn==1){
                answer.push_back({i,n-j,0});
            }
            if(ground[j][i].isGirder==1){
                answer.push_back({i,n-j,1});
            }
        }
    }
    // for(int i=0;i<n+1;i++){
    //     for(int j=n;j>=0;j--){
    //         if(ground[i][j].isColumn==1) answer.push_back({i,n-j,0});
    //         if(ground[i][j].isGirder==1) answer.push_back({i,n-j,1});
    //     }
    // }

    // for(int i=0;i<answer.size();i++){
    //     cout << answer[i][0] << "," << answer[i][1] << ","  << answer[i][2] << endl;
    // }
    return answer;
}