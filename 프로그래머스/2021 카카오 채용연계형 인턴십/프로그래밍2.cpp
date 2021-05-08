#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    char room[5][5];
    int oneDir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int twoDir[8][2]={{2,0},{0,2},{-2,0},{0,-2},{1,1},{1,-1},{-1,1},{-1,-1}};
    int findDir[4][2]={{0,0},{0,1},{1,0},{1,1}};
    int tmpX,tmpY;
    bool flag;
    for(int i=0;i<5;i++){
        
        flag = true;
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++) room[j][k]= places[i][j][k];
        }
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(room[j][k]=='P'){
                    for(int l=0;l<4;l++){
                        tmpX = j+oneDir[l][0];
                        tmpY = k+oneDir[l][1];
                        if(tmpX>=0 && tmpX<5 && tmpY>=0 && tmpY<5 && room[tmpX][tmpY]=='P'){
                            flag = false;
                            break;
                        }
                    }
                    if(flag==false) break;
                    for(int l=0;l<8;l++){
                        tmpX = j+twoDir[l][0];
                        tmpY = k+twoDir[l][1];
                        if(tmpX>=0 && tmpX<5 && tmpY>=0 && tmpY<5 && room[tmpX][tmpY]=='P'){
                            if(j==tmpX){
                                tmpY= min(tmpY,k);
                                if(room[tmpX][tmpY+1]=='X') continue;
                                else{

                                    flag = false;
                                    break;
                                }
                            }
                            else if(k==tmpY){
                                tmpX= min(tmpX,j);
                                if(room[tmpX+1][tmpY]=='X') continue;
                                else{

                                    flag = false;
                                    break;
                                }
                            }
                            else{
                                tmpX = min(tmpX,j);
                                tmpY = min(tmpY,k);
                                for(int m=0;m<4;m++){
                                    if(room[tmpX+findDir[m][0]][tmpY+findDir[m][1]]=='O'){
                                        flag = false;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                if(flag==false) break;
            }
            if(flag==false) break;
        }
        if(flag==false) answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}

// #include <string>
// #include <vector>
// #include <queue>
// #include <math.h>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// int dir[2][2] = {{0,1},{1,0}};
// bool DFSFlag;
// void DFS(vector<vector<char>> room, int x, int y, int dist){
//     if(DFSFlag==false) return;
//     if(dist==2) return;
//     int tmpX,tmpY;
//     for(int i=0;i<2;i++){
//         tmpX = x + dir[i][0];
//         tmpY = y + dir[i][1];
//         if(tmpX>=0 && tmpX<5 && tmpY>=0 && tmpY<5){
//             if(room[tmpX][tmpY]=='O'){
//                 DFS(room,tmpX,tmpY,dist+1);
//             }
//             else if(room[tmpX][tmpY]=='P'){
//                 DFSFlag=false;
//                 return;
//             }
//         }
//     }
// }
// vector<int> solution(vector<vector<string>> places) {
//     vector<int> answer;
//     int tmpX,tmpY;
//     bool flag;
//     vector<vector<char>> room(5,vector<char> (5));
//     for(int i=0;i<5;i++){
//         flag = true;
//         for(int j=0;j<5;j++){
//             for(int k=0;k<5;k++) {
//                 room[j][k] = places[i][j][k];
//             }
//         }
//         for(int j=0;j<5;j++){
//             for(int k=0;k<5;k++){
//                 if(room[j][k]=='P') {
//                     DFSFlag = true;
//                     DFS(room, j, k, 0);
//                     if(DFSFlag==false){
//                         answer.push_back(0);
//                         flag=false;
//                         break;
//                     }
//                 }
//             }
//             if(flag==false)break;
//         }
//         if(flag==true) answer.push_back(1);
//     }
//     return answer;
// }