#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct cmp{
    bool operator()(int A, int B){
        return A > B;
    }
};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,x,y;
    long long sum = 0;
    cin >> N;
    priority_queue <int, vector<int>, cmp> pq;

    for(int i=0;i<N;i++) {
        cin >> x;
        pq.push(x);
    }
    if(N==1){
        cout << "0\n";
        return 0;
    }
    while(pq.size()>=2){
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();
        sum += x+ y;
        if(pq.size()==0){
            cout << sum << "\n";
            return 0;
        }
        pq.push(x+y);
    }
    
    cout << sum << "\n";
    return 0;
}