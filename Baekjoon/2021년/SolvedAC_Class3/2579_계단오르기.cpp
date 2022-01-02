#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int total;
    cin >> total;
    vector<int> stair(total+1,0);
    for(int i=1;i<=total;i++) cin >> stair[i];
    if(total==1|| total==2){
        if(total==1) cout << stair[1];
        else cout << stair[1]+stair[2];
        return 0;
    }
    vector<int> sum(total+2,0);
    sum[0] = 0;
    sum[1] = stair[1];
    sum[2] = stair[1]+stair[2];
    for(int i=3;i<=total;i++){
        sum[i] = max(sum[i-3]+stair[i-1]+stair[i],sum[i-2]+stair[i]); 
    }
    cout << sum[total] << endl;
    return 0;
}