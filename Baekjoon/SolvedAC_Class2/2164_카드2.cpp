#include<iostream>
#include<queue>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,ans;
    cin >> N;
    queue<int> q;
    for(int i=1;i<=N;i++) q.push(i);
    while(!q.empty()){
        ans = q.front();
        q.pop();
        if(q.empty()) break;
        ans = q.front();
        q.pop();
        q.push(ans);
    }
    cout << ans << "\n";
    return 0;
}