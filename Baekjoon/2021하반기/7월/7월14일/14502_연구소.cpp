#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
typedef long long ll;

using namespace std;
int safearea;
int N, M;

void countSafe(vector<vector<int>> map)
{
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    queue<pair<int,int>> q;
    int x,y,tmpx,tmpy;
    int tmpSafe=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==2){
                q.push({i,j});
                while(!q.empty()){
                    x=q.front().first;
                    y=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        tmpx=x+dir[k][0];
                        tmpy=y+dir[k][1];
                        if(tmpx>=0 && tmpx<N && tmpy>=0 && tmpy<M){
                            if(map[tmpx][tmpy]==0){
                                map[tmpx][tmpy]=2;
                                q.push({tmpx,tmpy});
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==0) tmpSafe ++;
        }
    }
    if(safearea < tmpSafe) safearea=tmpSafe;
}

void findMap(vector<vector<int>> map, int x, int y)
{
    map[x][y] = 1;
    for (int i = x; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == x)
            {
                if (j > y)
                {
                    if (map[i][j] == 0)
                    {
                        map[i][j] = 1;
                        for (int a = i; a < N; a++)
                        {
                            for (int b = 0; b < M; b++)
                            {
                                if (a == i)
                                {
                                    if (b > j)
                                    {
                                        if (map[a][b] == 0)
                                        {
                                            map[a][b] = 1;
                                            countSafe(map);
                                            map[a][b] = 0;
                                        }
                                    }
                                }
                                else
                                {
                                    if (map[a][b] == 0)
                                    {
                                        map[a][b] = 1;
                                        countSafe(map);
                                        map[a][b] = 0;
                                    }
                                }
                            }
                        }
                        map[i][j] = 0;
                    }
                }
            }
            else
            {
                if (map[i][j] == 0)
                {
                    map[i][j] = 1;
                    for (int a = i; a < N; a++)
                    {
                        for (int b = 0; b < M; b++)
                        {
                            if (a == i)
                            {
                                if (b > j)
                                {
                                    if (map[a][b] == 0)
                                    {
                                        map[a][b] = 1;
                                        countSafe(map);
                                        map[a][b] = 0;
                                    }
                                }
                            }
                            else
                            {
                                if (map[a][b] == 0)
                                {
                                    map[a][b] = 1;
                                    countSafe(map);
                                    map[a][b] = 0;
                                }
                            }
                        }
                    }
                    map[i][j] = 0;
                }
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    safearea = 0;
    // 0 : 빈 칸, 1 : 벽, 2 : 바이러스
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
                findMap(map, i, j);
        }
    }

    cout << safearea;
    return 0;
}