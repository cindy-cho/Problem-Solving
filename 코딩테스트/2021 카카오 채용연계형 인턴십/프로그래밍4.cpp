#include <string>
#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 2100000000

struct compare{
    bool operator()(pair<int,int> A, pair<int,int> B){
        return A.second > B.second;
    }
};

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    vector < int > trap(n,0);
    priority_queue <pair<int,int>, vector<pair<int,int>>, compare> pq;
    pair<int,int> cur;
    vector < vector < int > > room (n, vector<int> (n,INF));
    vector <int> min(n,INF);
    for(int i=0;i<traps.size();i++) trap[traps[i]-1] = 1;
    for(int i=0;i<roads.size();i++){
        if(room[roads[i][0]-1][roads[i][1]-1]== INF) room[roads[i][0]-1][roads[i][1]-1]= roads[i][2];
        else if(room[roads[i][0]-1][roads[i][1]-1] > roads[i][2]) room[roads[i][0]-1][roads[i][1]-1]= roads[i][2];
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++) cout << room[i][j] << " ";
    //     cout << endl;
    // }
    // // cout << "traps\n";
    // for(int i=0;i<n;i++) cout << min[i] << " ";
    // cout << endl;
    start--;
    end --;
    min[start]=0;
    pq.push({start,0});
    while(!pq.empty()){
        cur = pq.top();
        pq.pop();
        // cout << cur.first << "," << cur.second << endl;
        if(trap[cur.first]==1){
            for(int i=0;i<n;i++){
                swap(room[cur.first][i],room[i][cur.first]);
            }
        }
        if(cur.second <= min[cur.first]){
            for(int i=0;i<n;i++){
                if(room[cur.first][i]!=INF){
                    if(min[i] > min[cur.first]+room[cur.first][i]){
                        min[i] = min[cur.first]+room[cur.first][i];
                        pq.push({i,min[i]});
                    }
                }
            }
        }
        

        // for(int i=0;i<n;i++){
        // for(int j=0;j<n;j++) cout << room[i][j] << " ";
        //     cout << endl;
        // }
        // cout << "traps\n";
        // for(int i=0;i<n;i++) cout << min[i] << " ";
        // cout << endl;
    }

    answer = min[end];
    return answer;
}