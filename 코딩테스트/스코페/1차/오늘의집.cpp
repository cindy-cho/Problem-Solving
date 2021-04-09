#include<iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
    int N,i,j,k,total=0,product=0, side,flag;
    int dir[3][2]={{0,1},{1,0},{1,1}};
    cin >> N;
    vector <string > space(N);
    int newSpace[50][50][50] = {0,};
    vector <int > ans;
    cin.ignore();
    for(i=0;i<N;i++) getline(cin,space[i]);
    //1인 정사각형 기본 setting
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(space[i][j]=='1'){
                newSpace[0][i][j] = 1;
                product ++;
            }
        }
    }
 

    side = 1;
    while(product !=0){
        
        total+=product;
        ans.push_back(product);
        product = 0;
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                if(newSpace[side-1][i][j]==1 && i+1<N && j+1<N){
                    flag=1;
                    for(k=0;k<3;k++) if(newSpace[side-1][i+dir[k][0]][j+dir[k][1]]==0) {
                        flag=-1;
                        break;
                    }
                    if(flag==1){
                        product ++;
                        newSpace[side][i][j]=1;
                    } 
                }
            }
        }
        N--;
        side++;
    }
    cout<< "total: " << total << "\n";
   
    for(i=0;i<ans.size();i++) cout<< "size[" << i+1 << "]: " << ans[i] << "\n";
    return 0;
}