#include<iostream>
#include<vector>
using namespace std;

typedef struct{
    int x;
    int y;
    int dir;
}robots;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A,B,N,M;
    int robotIdx, order, repeat;
    char c;
    cin >> A >> B;
    cin >> N >> M;
    vector<robots> ROBOT(N);
    vector<vector<int>> MAP(B, vector<int> (A,0));

    for(int i=0;i<N;i++){
        cin >> ROBOT[i].x >> ROBOT[i].y >> c;
        if(c=='N') ROBOT[i].dir = 0;
        else if(c=='E') ROBOT[i].dir = 1;
        else if(c=='S') ROBOT[i].dir = 2;
        else if(c=='W') ROBOT[i].dir = 3;
        ROBOT[i].x--;
        ROBOT[i].y = B-ROBOT[i].y;
        MAP[ROBOT[i].y][ROBOT[i].x] = i+1;
        
    }

    for(int i=0;i<M;i++){
        cin >> robotIdx >> c >> repeat;
        robotIdx--;
        if(c=='L')  order = 0;
        else if(c=='R') order = 1;
        else if(c=='F') order = 2;
        for(int j=0;j<repeat;j++){
            if(order==0) ROBOT[robotIdx].dir = (ROBOT[robotIdx].dir+3) % 4;
            else if(order==1) ROBOT[robotIdx].dir = (ROBOT[robotIdx].dir+1) % 4;
            else if(order==2){
                MAP[ROBOT[robotIdx].y][ROBOT[robotIdx].x] = 0;
                if(ROBOT[robotIdx].dir==0) ROBOT[robotIdx].y--;
                else if(ROBOT[robotIdx].dir==1) ROBOT[robotIdx].x++;
                else if(ROBOT[robotIdx].dir==2) ROBOT[robotIdx].y++;
                else if(ROBOT[robotIdx].dir==3) ROBOT[robotIdx].x--;
        
                if(ROBOT[robotIdx].y<0 || ROBOT[robotIdx].y>=B || ROBOT[robotIdx].x<0 || ROBOT[robotIdx].x>=A){
                    cout << "Robot " << robotIdx+1 << " crashes into the wall\n";
                    return 0;   
                }
                else if(MAP[ROBOT[robotIdx].y][ROBOT[robotIdx].x]!=0){ //다른 로봇과 충돌
                    cout << "Robot " << robotIdx+1 << " crashes into robot " << MAP[ROBOT[robotIdx].y][ROBOT[robotIdx].x] <<"\n";
                    return 0;
                } 
                MAP[ROBOT[robotIdx].y][ROBOT[robotIdx].x] = robotIdx+1;
            }
        }
    }
    cout << "OK\n" ;
    return 0;
}