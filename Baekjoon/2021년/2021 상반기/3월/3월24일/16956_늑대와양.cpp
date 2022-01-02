#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int R,C,i,j;
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int x,y,tmpx,tmpy;
    queue < pair <int ,int > > q;
    cin >> R >> C ;
    char map[500][500];
    for(i=0;i<R;i++){
        for(j=0;j<C;j++) {
            cin >> map[i][j];
            
       
        if(map[i][j]=='S'){
        //    cout << i << "," << j << endl;
            q.push(make_pair(i,j)); //양 위치 넣어준다.
        }}
        cin.ignore();
        
    }

    while(!q.empty()){
        x= q.front().first;
        y= q.front().second;
        q.pop();
        map[x][y] = 'V';
        
        for(i=0;i<4;i++){
            tmpx = x+dir[i][0];
            tmpy = y+dir[i][1];
            if(tmpx>=0 && tmpx<R && tmpy>=0 && tmpy<C){
                if(map[tmpx][tmpy]=='.') map[tmpx][tmpy] = 'D';
                else if(map[tmpx][tmpy]=='S'){
                    q.push(make_pair(tmpx,tmpy));
                }
                else if(map[tmpx][tmpy]=='W'){
                    cout << "0\n" ;
                    return 0;
                }
            }
        }
    }

    cout << "1\n";
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            if(map[i][j]=='V') cout << 'S';
            else cout << map[i][j];
        }
        cout << "\n";
    }

    return 0;
}