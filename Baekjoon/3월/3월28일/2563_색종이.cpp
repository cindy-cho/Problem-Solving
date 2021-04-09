#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int map[101][101]={0,};
    int N,a,b;
    int i,j,k;
    int ans=0;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> a >> b;
        for(j=a;j<a+10;j++){
            for(k=b;k<b+10;k++) map[j][k]=1;
        }
    }

    for(i=0;i<101;i++){
        for(j=0;j<101;j++){
            if(map[i][j]==1) ans ++;
        }
    }
    cout << ans << "\n";
    return 0;
}