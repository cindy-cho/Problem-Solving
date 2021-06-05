#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define endl '\n'
typedef long long ll;
using namespace std;

class Solution {
private:
    ll modulo = 1000000007;
    struct cmp{
        bool operator()(pair<int,int> A, pair<int,int> B){
            if(A.second==B.second) return A.first < B.first;
            return A.second < B.second;
        }
    };
    struct comp{
        bool operator()(int A, int B){
            return A > B;
        }
    };

public:
    int maxWrongPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        priority_queue<int,vector<int>,comp> pqSpd;
        int count=0;
        ll sum=0,workSnd,work=0;
        pair<int,int> crnt;
        for(int i=0;i<n;i++) pq.push({speed[i],efficiency[i]});
        while(!pq.empty()){
            crnt = pq.top();
            pq.pop();
            if(count<k){
                sum += crnt.first;
                sum %= modulo;
                pqSpd.push(crnt.first);
                work = ( sum * crnt.second )% modulo;    
                count++;
            }
            else{
                workSnd = ((sum - pqSpd.top() + crnt.first) * crnt.second ) % modulo;
                if(workSnd>work){
                    work = workSnd;
                    sum = sum - pqSpd.top() + crnt.first;
                    sum %= modulo;
                    pqSpd.pop();
                    pqSpd.push(crnt.first);
                }
            }
        }
        return work;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        priority_queue<int,vector<int>,comp> pqSpd;
        int count=0;
        ll sum=0,workSnd,workTrd,work=0;
        pair<int,int> crnt;
        for(int i=0;i<n;i++) pq.push({speed[i],efficiency[i]});
        while(!pq.empty()){
            crnt = pq.top();
            pq.pop();
            if(count<k){
                workSnd = ((sum + crnt.first) * crnt.second) % modulo;
                if(!pqSpd.empty()) workTrd = ((sum - pqSpd.top() + crnt.first) * crnt.second ) % modulo;
                else workTrd = 0;
                if(workSnd>work && workSnd>workTrd){
                    work = workSnd;
                    sum = sum + crnt.first;
                    sum %= modulo;
                    pqSpd.push(crnt.first);
                    count ++;
                }
                else if(workTrd>work && workTrd>workSnd){
                    work = workTrd;
                    sum = sum - pqSpd.top() + crnt.first;
                    sum %= modulo;
                    pqSpd.pop();
                    pqSpd.push(crnt.first);
                }
            }
            else{
                workSnd = ((sum - pqSpd.top() + crnt.first) * crnt.second ) % modulo;
                if(workSnd>work){
                    work = workSnd;
                    sum = sum - pqSpd.top() + crnt.first;
                    sum %= modulo;
                    pqSpd.pop();
                    pqSpd.push(crnt.first);
                }
            }
            cout << crnt.first << "," << crnt.second << " : " << work << ", sum : " << sum <<  endl;
        }
        return work;
    }
};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector <int> speed(n),efficiency(n);

    for(int i=0;i<n;i++) cin >> speed[i] ;
    for(int i=0;i<n;i++) cin >> efficiency[i] ;
    
    Solution S;

    cout << S.maxPerformance(n,speed,efficiency,k) << endl;
    
    return 0;
}