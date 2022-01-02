#include <iostream>
#include <stack>

using namespace std;

int main(void){
    int map[53][53]={0,};
    int T,N,M,K,Y,X;
    int i,j,a,b,xx,yy,nx,ny;
    int dir[4][2]= {{0,1},{0,-1},{1,0},{-1,0}};
    int ans;
    stack <pair <int, int > > s;

    cin >> T;
    for(i=0;i<T;i++){
        ans=0;
        cin >> M >> N >> K;
        for(j=0;j<53;j++) for(a=0;a<53;a++) map[j][a]=0;
        for(j=0;j<K;j++){
            cin >> X >> Y;
            map[Y][X]= 1;
        }
        for(j=0;j<N;j++){
            for(a=0;a<M;a++){
                if(map[j][a]==1){
                    s.push(make_pair(j,a));
                    map[j][a]=0;
                    while(!s.empty()){
                        xx = s.top().first;
                        yy = s.top().second;
                        s.pop();
                        for(b=0;b<4;b++){
                            nx = xx + dir[b][0];
                            ny = yy + dir[b][1];
                            if(nx>=0 && nx<N && ny>=0 && ny<M && map[nx][ny]==1){
                                s.push(make_pair(nx,ny));
                                map[nx][ny]=0;
                            }
                        }
                    }
                    ans ++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}