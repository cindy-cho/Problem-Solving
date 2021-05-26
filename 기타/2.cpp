#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> maps, int p, int r) {
    int answer = 0;
    int mapSize = maps.size();
    int range = mapSize+1;
    vector<vector<int>> score(range,vector<int> (range,0));
    int maxShoot=0;
    int tX=0,tY=0,shoot;
    int tmpX,tmpY;

    r /= 2;

    for(int ii=0;ii<range;ii++){
        for(int jj=0;jj<range;jj++){
            shoot =  0;
            tX = ii;
            tY = jj;
            for(int i=1;i<=r;i++){
                tmpX = tX -( r + 1 - i);
                tmpY = tY  - i;
                tmpX --;
                tmpY --;
                for(int j=1;j<=i*2;j++){  //  2,4,6 ...
                    if(tmpX>=0 && tmpX<mapSize && tmpY>=0 && tmpY<mapSize){
                        if(j==1 || j == (i*2)){
                            if(maps[tmpX][tmpY] <= p/2) shoot++;
                        }
                        else if(maps[tmpX][tmpY] <= p) shoot++;
                    }
                    tmpY++;
                }
            }

            for(int i=r;i>=1;i--){
                tmpX = tX + (r + 1 -  i);
                tmpY = tY - i;
                tmpX -=2;
                tmpY --;
                for(int j=1;j<=i*2;j++){  // 6,4,2 ...
                    if(tmpX>=0 && tmpX<mapSize && tmpY>=0 && tmpY<mapSize){
                        if(j==1 || j == (i*2)){
                            if(maps[tmpX][tmpY] <= p/2) shoot++;
                        }
                        else if(maps[tmpX][tmpY] <= p) shoot++;
                    }
                    tmpY++;
                }
            }

            if(shoot>maxShoot) maxShoot = shoot;
        }
    }
    
    answer = maxShoot;

    return answer;
}