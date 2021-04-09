#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M,i,j , count;
    int m=0, total=0, total2=0;
    int NM[100][100];
    cin>> N >> M;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            cin >> NM[i][j] ;
            if(j==0) total+=NM[i][j];
            else if(NM[i][j]>NM[i][j-1]) total+=NM[i][j]-NM[i][j-1];
        }  
    }
    for(j=0;j<M;j++){
        for(i=0;i<N;i++){
            if(i==0) total2+=NM[i][j];
            else if(NM[i][j]>NM[i-1][j]) total2+=NM[i][j]-NM[i-1][j];
        }
    }
    cout << N*M*2 + total*2 +  total2*2 << "\n";
    return 0;
}