#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M=key.size(),N=lock.size();
    int totalKey = 0, tmpKey=0,flag;
    for(int j=0;j<N;j++){
        for(int k=0;k<N;k++) if(lock[j][k]==0) totalKey ++;
    }
    if(totalKey==0) return true;
    for(int i=0;i<4;i++){
        if(i!=0){ //90도씩 키를 회전~~~~~~~
            reverse(key.begin(),key.end());
            for(int j=0;j<M;j++){
                for(int k=j+1;k<M;k++){
                    swap(key[j][k],key[k][j]);
                }
            }
        }

        for(int j=-N;j<N;j++){
            for(int k=-N;k<N;k++){
                tmpKey = 0;
                flag = 1;
                for(int a=0;a<M;a++){
                    for(int b=0;b<M;b++){
                        if(j+a>=0 && j+a<N && k+b>=0 && k+b<N){ //범위 안에 있는 것만 체크
                            if(lock[j+a][k+b]==0 && key[a][b]==1) tmpKey++;
                            else if(lock[j+a][k+b]==1 && key[a][b]==0) continue;
                            else{
                                flag = -1;
                                break;
                            }
                        }
                    }
                    if(flag==-1) break;
                }
                if(flag==1 && tmpKey==totalKey) return true;
            }
        }
    }
    return false;
}