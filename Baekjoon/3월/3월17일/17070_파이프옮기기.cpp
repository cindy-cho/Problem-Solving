 #include <iostream>
 #include <vector>
 #include <queue>

 using namespace std;

typedef struct{
    int x;
    int y;
    int status;
}PIP;

 int main(void){
     int N,i,j,ans=0,flag=0;
     int x=0,y=0,mode=0; //0 가로 1 세로 2 대각선
     PIP tmp, current;
     queue < PIP > q;
     int mov[3][2]={{0,1},{1,0},{1,1}};
     
     cin >> N;
     vector < vector <int > > pipe (N, vector<int> (N,0));
     for(i=0;i<N;i++) for(j=0;j<N;j++) cin >> pipe[i][j];
     
     //목적지가 1이면 이동시킬 수 없음
     if(pipe[N-1][N-1]==1) cout << 0 << endl;

     //그렇지 않은 경우에만 탐색
     else{
        tmp.x=x;
        tmp.y=y;
        tmp.status=0;
        q.push(tmp);
        while(!q.empty()){
            tmp.x=q.front().x;
            tmp.y=q.front().y;
            tmp.status=q.front().status;
           
            current.x=tmp.x+mov[tmp.status][0];
            current.y=tmp.y+mov[tmp.status][1];
           
            q.pop();

            if(current.x==(N-1) && current.y==(N-1)) ans ++; //목적지면 ans++
            else{ //목적지에 도착한경우는 추가 탐색 X
                if(tmp.status==0){
                    tmp.x=current.x+mov[0][0];
                    tmp.y=current.y+mov[0][1];
                    current.status=0;
                    if(tmp.x<N && tmp.y<N && pipe[tmp.x][tmp.y]==0) q.push(current);
                }
                else if(tmp.status==1){
                    tmp.x=current.x+mov[1][0];
                    tmp.y=current.y+mov[1][1];
                    current.status=1;
                    if(tmp.x<N && tmp.y<N && pipe[tmp.x][tmp.y]==0) q.push(current);
                }
                else if(tmp.status==2){
                    tmp.x=current.x+mov[0][0];
                    tmp.y=current.y+mov[0][1];
                    current.status=0;
                    if(tmp.x<N && tmp.y<N && pipe[tmp.x][tmp.y]==0) q.push(current);
                    tmp.x=current.x+mov[1][0];
                    tmp.y=current.y+mov[1][1];
                    current.status=1;
                    if(tmp.x<N && tmp.y<N && pipe[tmp.x][tmp.y]==0) q.push(current);
                }
                flag=0;
                current.status=2;
                for(i=0;i<3;i++){
                    tmp.x=current.x+mov[i][0];
                    tmp.y=current.y+mov[i][1];
                    if(tmp.x<N && tmp.y<N && pipe[tmp.x][tmp.y]==0) flag ++;
                }
                if(flag==3) q.push(current);
            }
        }
        

        cout << ans << endl;
     }
     return 0;
 }