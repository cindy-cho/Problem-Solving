#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    
    cin >> N;
    int schedule[16][2];
    int money[16];

    for(int i=0;i<N;i++){
        cin >> schedule[i][0] >> schedule[i][1];
        money[i]=0;
    }
    money[N]=0;
    for(int i=N-1;i>=0;i--){
        if(i+schedule[i][0]>N) money[i]=money[i+1];
        else money[i] = max(money[i+1],money[i+schedule[i][0]]+schedule[i][1]);
    }
    // for(int i=0;i<N;i++) cout << money[i] << " ";
    // cout << "\n";
    cout << money[0] << "\n";
    return 0;
}