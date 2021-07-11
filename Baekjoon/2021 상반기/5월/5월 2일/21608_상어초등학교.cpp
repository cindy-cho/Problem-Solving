#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int tmpj, tmpk;
    int ID;
    int maxLike, R, C, tmpLike, tmpBlank;
    int maxCount,maxBlank;
    int ANS=0;
    int flag;
    cin >> N;
    vector < vector < int > > room (N, vector<int> (N, 0));
    vector < vector < int > > student (N*N, vector<int> (5,0)); 

    for(int i=0;i<N*N;i++){
        cin >> ID;
        student[ID-1][0] = ID;
        ID--;
        cin >> student[ID][1] >>student[ID][2] >> student[ID][3]>>student[ID][4];
        if(i==0){
            room[1][1] = student[ID][0];
        }
        else{
            maxLike=-1;
            maxBlank=-1;
            flag = 1;
            for(int j=0;j<N;j++){
                for(int k=0;k<N;k++){
                    if(room[j][k]==0){
                        tmpLike=0;
                        tmpBlank=0;
                        for(int l=0;l<4;l++){
                            tmpj=j+dir[l][0];
                            tmpk=k+dir[l][1];
                            if(tmpj>=0 && tmpj<N && tmpk>=0 && tmpk<N){
                                if(room[tmpj][tmpk]==0) tmpBlank++;
                                else if(room[tmpj][tmpk]!=0){
                                    for(int p=1; p<5;p++){
                                        if(student[ID][p]==room[tmpj][tmpk]){
                                            tmpLike++;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if(tmpLike > maxLike){
                            maxLike = tmpLike; 
                            maxBlank = tmpBlank;
                            R = j;
                            C = k;
                            // cout << "UPDATE max : " << R << "," << C << endl;
                        }
                        else if(tmpLike == maxLike){
                            // cout << tmpBlank << "," << maxBlank << endl;
                            if(tmpBlank > maxBlank){
                                maxBlank = tmpBlank;
                                R = j;
                                C = k;
                                // cout << "UPDATE BLANK : " << R << "," << C << endl;
                            }
                        }
                    }
                }
            }
            room[R][C] = student[ID][0];
        }
    }
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++) cout << room[i][j] << " ";
    //     cout << endl;
    // }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            // cout << room[i][j] << " : " ;
            tmpLike=0;
            for(int l=0;l<4;l++){
                tmpj=i+dir[l][0];
                tmpk=j+dir[l][1];
                if(tmpj>=0 && tmpj<N && tmpk>=0 && tmpk<N){
                    for(int p=1;p<5;p++){
                        if(student[room[i][j]-1][p]==room[tmpj][tmpk]){
                            tmpLike++;
                            // cout << "HIT ! : " << tmpj << ", " << tmpk << endl;
                            break;
                        }
                    }
                }
            }
            if(tmpLike==2) tmpLike = 10;
            else if(tmpLike==3) tmpLike = 100;
            else if(tmpLike==4) tmpLike = 1000;
            ANS += tmpLike;
        }
    }

    cout << ANS << "\n";
    return 0;
}



// 4 2 5 1 7
// 3 1 9 4 5
// 9 8 1 2 3
// 8 1 9 3 4
// 7 2 3 4 8
// 1 9 2 5 7
// 6 5 2 3 4
// 5 1 9 2 8
// 2 9 3 1 4