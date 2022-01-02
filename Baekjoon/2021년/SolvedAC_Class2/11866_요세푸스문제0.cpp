#include<iostream>
#include<queue>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    int N,K,tmp,idxFlag=0;
    cin >> N >> K;
    for(int i=1;i<=N;i++) q.push(i);
    if(N==1){
        cout << "<1>" << endl;
        return 0;
    }
    while(!q.empty()){
        for(int i=0;i<K-1;i++){
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        tmp = q.front();
        q.pop();
        if(idxFlag==0) cout << "<" << tmp << ",";
        else if (idxFlag==N-1) cout << " " << tmp << ">" << endl;
        else cout << " " << tmp << ",";
        idxFlag++;
    }
    
    return 0;
}