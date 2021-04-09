#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>


using namespace std;


int combination(vector<int> player, vector<int> team, int r, int index, int depth);
int minimun = INT_MAX;
int score[20][20] = {0,};

int main(void){
    int N;
    vector <int> player;
    
    scanf("%d",&N);
    int i,j,value;
    for(i=0;i<N;i++) player.push_back(i);

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d",&score[i][j]);
        }
    }
    N=N/2+N%2;

    vector <int> team(N);

    int flag=1;
    flag = combination(player, team, N, 0, 0);

    cout << minimun ;

    return 0;
}


int combination(vector<int> player, vector<int> team, int r, int index, int depth){
    if(r==0){
        int teamAScore=0, teamBScore=0;
        vector<int> teamB;
        int i,j;
        for( i=0;i<player.size();i++){
            if(find(team.begin(),team.end(),player[i])==team.end()){ //없으면
                teamB.push_back(player[i]); 
            }
        }

        for(i=0;i<team.size();i++){
            for(j=i+1;j<team.size();j++){
                teamAScore += score[team[i]][team[j]] + score[team[j]][team[i]];
                teamBScore += score[teamB[i]][teamB[j]] + score[teamB[j]][teamB[i]];
            }
        }

        minimun = min(minimun, abs(teamAScore-teamBScore));
    }

    else if(depth==player.size()){
        if(minimun==0) return -1;
    }

    else{
        team[index] = player[depth];
       
        if(combination(player,team, r-1, index+1, depth+1)==-1) return -1;
       
        if(combination(player, team, r,index, depth+1)==-1) return -1;
    }

    return 1;
}