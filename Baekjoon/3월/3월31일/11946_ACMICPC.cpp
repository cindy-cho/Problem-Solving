#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

typedef struct{
    int teamidx;
    int time;
    int problem;
}INFO; 

bool cmp(INFO a, INFO b){
    if(a.problem==b.problem){
        if(a.time==b.time){
            return a.teamidx < b.teamidx;
        }
        return a.time < b.time;
    }
    return a.problem > b.problem;
}



int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    int time, teamNum, problemmNum;
    string testRes;
    cin >> n>> m>> q;
     //팀별 통과 시간, 문제
    vector < INFO >  score (n);
    vector < vector < int > > passStatus (n, vector <int > (m,0));
    int i;
    for(i=0;i<n;i++) {
        score[i].time=0;
        score[i].problem = 0;
        score[i].teamidx=i+1;
    }
    for(i=0;i<q;i++){
        cin >> time >> teamNum >> problemmNum >> testRes ;
        if(testRes=="RE" || testRes=="TLE" || testRes == "WA"){
            if(passStatus[teamNum-1][problemmNum-1]==-1) continue;
            passStatus[teamNum-1][problemmNum-1]++;
        }
        else if(testRes=="AC"){
            if(passStatus[teamNum-1][problemmNum-1]==-1) continue;
            score[teamNum-1].time += time + 20 *passStatus[teamNum-1][problemmNum-1];
            score[teamNum-1].problem ++;
            passStatus[teamNum-1][problemmNum-1] = -1;
        }
    }

    sort(score.begin(),score.end(),cmp);

    for(i=0;i<n;i++){
        cout << score[i].teamidx << " " << score[i].problem << " " << score[i].time << "\n";
    }
    return 0;
}