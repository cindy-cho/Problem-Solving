#include<iostream>
#include<vector>

#define INF 2100000000
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,H;
    
    cin >> N >> H;
    int input;
    int downHigh=0,downLow=H,upHigh=0,upLow=H;
    int min=500000;
    int ans=0;
    vector<int> LOW(H,0);
    vector<int> HIGH(H,0);
    
    for(int i=0;i<N;i++){
        cin >> input;
        if(i%2==0) LOW[input-1]++;
        else HIGH[H-input]++;
    }

    for(int i=H-2;i>=0;i--){
        LOW[i] = LOW[i] + LOW[i+1];
        HIGH[H-i-1] = HIGH[H-i-1] + HIGH[H-i-2];
    }
    for(int i=0;i<H;i++){
        LOW[i] = LOW[i] + HIGH[i];
        if(LOW[i] < min) min = LOW[i];
    }
    for(int i=0;i<H;i++){
        if(LOW[i]==min) ans++;
    }
    
    cout << min << " " << ans << "\n";

    return 0;
}