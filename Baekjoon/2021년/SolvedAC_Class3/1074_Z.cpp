#include<iostream>
#include<math.h>
#define endl '\n'
typedef long long ll;

using namespace std;
int dir[4][2] = {{0,0},{0,1},{1,0},{1,1}};
int r,c;
int findDepth(int x,int y,int N,int vst){
    if(N==0) return vst;
    int E = pow(2,N-1);
    int tmpx,tmpy;
    for(int i=0;i<4;i++){
        tmpx = x + E*dir[i][0];
        tmpy = y + E*dir[i][1];
        if(r>=tmpx && r<tmpx+E && c>=tmpy && c<tmpy+E){
            vst = findDepth(tmpx,tmpy,N-1,vst+i*E*E);
            break;
        }
    }
    return vst;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N >> r >> c;
    
    cout << findDepth(0,0,N,0) << endl;

    return 0;
}