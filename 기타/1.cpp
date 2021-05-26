#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct{
    int arrival;
    int id;
    int rank;
}customer;

struct compare{
    bool operator()(customer A, customer B){
        if(A.rank == B.rank){
            if(A.arrival == B.arrival){
                return A.id > B.id;
            }
            return A.arrival > B.arrival;
        }
        return A.rank > B.rank;
    }
};

bool cmp(customer A, customer B){
    return A.arrival < B.arrival;
}

vector<int> solution(vector<int> t, vector<int> r) {
    vector<int> answer;
    int len = t.size();
    int endTime = 0;
    int idx=0;
    priority_queue <customer, vector<customer> , compare> pq;
    vector<customer> inOrder(len);
    customer tmp;
    for(int i=0;i<len;i++){
        inOrder[i].id = i;
        inOrder[i].rank = r[i];
        inOrder[i].arrival = t[i];
        if(endTime < t[i]) endTime=t[i];
    }

    sort(inOrder.begin(), inOrder.end(), cmp);

    for(int i=0;i<=endTime;i++){
        while(inOrder[idx].arrival <=i && idx<len){
            pq.push(inOrder[idx]);
            idx++;
        }
        if(!pq.empty()){
            tmp = pq.top();
            pq.pop();
            // cout << "for push : " << tmp.id << endl;
            answer.push_back(tmp.id);
        }
    }
    while(!pq.empty()){
        tmp = pq.top();
        pq.pop();
        // cout << "while push : " << tmp.id << endl;
        answer.push_back(tmp.id);
    }

    return answer;
}