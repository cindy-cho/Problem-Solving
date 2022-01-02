#include<iostream>
#include<vector>
#include<queue>
#include<map>
#define endl '\n'
typedef long long ll;

using namespace std;

vector<vector<int>> maps;

typedef struct{
    int x;
    int y;
    int val;
} block;

struct cmp{
    bool operator()(block A, block B){
        if(A.val == B.val){
            if(A.x == B.x){
                if(A.y < B.y) return true;
                else return false;
            }
            else if(A.x < B.x) return true;
        }
        if(A.val > B.val) return true;
        return false;
    }
};


int N,M;
int maxSum;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int vst[3][2];
void findMax(int x,int y,int stage,int sum){
    if(stage==3){
        if(sum>maxSum) {
            maxSum=sum;
        }
        return;
    }
    vst[stage][0] = x;
    vst[stage][1] = y;
    int tmpx, tmpy;
    bool flag;
    for(int i=0;i<4;i++){
        tmpx=x+dir[i][0];
        tmpy=y+dir[i][1];
        
        if(tmpx>=0 && tmpx<N && tmpy>=0 && tmpy<M){
            flag= true;
            for(int j=0;j<stage;j++){
                if(vst[j][0]==tmpx&& vst[j][1]==tmpy){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                findMax(tmpx,tmpy,stage+1,sum+maps[tmpx][tmpy]);
            }
        }
        
    }
    
}

void checkExcept(int x, int y){
    int sum;
    int tmpx, tmpy;
    int possible[4][3][2]={ { {0,1}, {0,2}, {-1,1} },
                            { {0,1}, {0,2}, {1,1} },
                            { {1,0}, {2,0}, {1,1} },
                            { {-1,1}, {0,1}, {1,1} } };
    bool flag;
    for(int i=0;i<4;i++){
        sum  = maps[x][y];
        flag= true;
        for(int j=0;j<3;j++){
            tmpx = x+possible[i][j][0];
            tmpy = y+possible[i][j][1];
            if(tmpx>=0 && tmpx<N && tmpy>=0 && tmpy<M){
                sum +=  maps[tmpx][tmpy];
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag==true && sum > maxSum) maxSum=sum;
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    maps.resize(N,vector<int>(M));

    maxSum=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) cin >> maps[i][j];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            findMax(i,j,0,maps[i][j]);
            checkExcept(i,j);
        }
    }

    cout << maxSum << endl;
    return 0;
}