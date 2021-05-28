#include<iostream>
#include<vector>
using namespace std;
int N;
int dir[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};

int isSum(int x,int y, vector<vector<int>> garden){
    int tmpx, tmpy, sum=0;
    for(int i=0;i<5;i++){
        tmpx=x+dir[i][0];
        tmpy=y+dir[i][1];
        sum = sum + garden[tmpx][tmpy];
    }
    return sum;
}
bool isBloom(int x, int y, int a, int b){
    int tmpx,tmpy,tmpa,tmpb;
    for(int i=0;i<5;i++){
        tmpx=x+dir[i][0];
        tmpy=y+dir[i][1];
        for(int j=0;j<5;j++){
            tmpa=a+dir[j][0];
            tmpb=b+dir[j][1];
            if(tmpa==tmpx && tmpy==tmpb) return false;
        }
    }
    return true;
}
bool isFlowerRange(int x, int y){
    int tmpx,tmpy;
    for(int i=0;i<5;i++){
        tmpx=x+dir[i][0];
        tmpy=y+dir[i][1];
        if(tmpx>=0 && tmpx<N && tmpy>=0 && tmpy<N) continue;
        else return false;
    }
    return true;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int sum,tmpx,tmpy,minAnswer=2100000;
    cin >> N;
    vector<vector<int>> garden(N, vector<int> (N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cin >> garden[i][j];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                for(int l=0;l<N;l++){
                    for(int a=0;a<N;a++){
                        for(int b=0;b<N;b++){
                            if( (i==k && j==l) || (i==a && j==b) || (k==a && l==b)) continue;
                            else{
                                if(isFlowerRange(i,j)==true && isFlowerRange(a,b)==true && isFlowerRange(k,l)==true && isBloom(i,j,k,l)==true && isBloom(i,j,a,b) && isBloom(k,l,a,b)==true){
                                    sum = isSum(i,j,garden) + isSum(k,l,garden) + isSum(a,b,garden);
                                    if(sum < minAnswer) minAnswer = sum;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << minAnswer << "\n";
    return 0;
}