#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
    int start;
    int damage;
}AD;

struct compare{
    bool operator()(AD A, AD B){
        return A.damage < B.damage;
    }
};

bool cmp(vector<int> A, vector<int> B){
    if(A[0]==B[0]){
        return A[1] > B[1];
    }
    return A[0] < B[0];
}
int solution(vector<vector<int>> ads) {
    int answer = 0;
    int start,end;
    AD tmp,tempTop;
    priority_queue <AD,vector<AD>,compare> pq;
    int totalSize = ads.size();
    sort(ads.begin(),ads.end(),cmp);
    
    start = ads[0][0]+5;
    for(int i=1;i<totalSize;i++){
        // cout << "start : " << start << endl;
        while(ads[i][0] <=start){
            tmp.start = ads[i][0];
            tmp.damage = ads[i][1];
            pq.push(tmp);
            i++;
            if(i==totalSize) break;
        }
        if(!pq.empty()){
            
            tmp = pq.top();
            pq.pop();
            answer += tmp.damage * (start - tmp.start);

            start = start + 5;
            // cout << answer << ", start time : " << start << endl;
             while(i<totalSize && ads[i][0] <=start){
                tmp.start = ads[i][0];
                tmp.damage = ads[i][1];
                pq.push(tmp);
                i++;
                if(i==totalSize) break;
            }
        }
        else{
            start = ads[i][0];
            start += 5;
        }
    }
    while(!pq.empty()){
            tmp = pq.top();
            pq.pop();
            answer += tmp.damage * (start - tmp.start);
            
            start = start + 5;
            // cout << answer << ", start time : " << start << endl;
        }
    return answer;
}