#include<iostream>
#include<vector>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    
    vector<int> DP(N+1,1000000);
    DP[1] = 0;

    for(int i=1;i<N+1;i++){
        if(i*3<=N) DP[i*3] = min(DP[i*3], DP[i]+1);
        if(i*2<=N) DP[i*2] = min(DP[i*2], DP[i]+1);
        if(i+1<=N) DP[i+1] = min(DP[i+1], DP[i]+1);
    }
    
    cout << DP[N] << endl;
    return 0;
}

/*
12 /3 = 4 / 2 = 2 -1 = 1 : 3 times

*/