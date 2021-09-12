#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#define endl '\n'
typedef long long ll;

using namespace std;
int button[10]; // 0,1,2,3....9,
int upperChannel(string channelNow){
    string
}
int lowerChannel(string channelNow){

}
int buttomMove(int N){

}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N=0, M, strLen, crnt;
    int dec=1;
    string strN;
    cin >> strN;
    cin >> M;
    strLen = strN.length();
    for(int i=strLen-1;i>=0;i--){
        crnt = strN[i]-'0';
        N+= crnt*dec;
        dec*=10;
    }
    for(int i=0;i<M;i++){
        cin >> crnt;
        button[crnt] = 1; // 1이면 고장난 버튼
    }
    upperChannel(strN);
    lowerChannel(strN);
    buttonMove(N);
    return 0;
}