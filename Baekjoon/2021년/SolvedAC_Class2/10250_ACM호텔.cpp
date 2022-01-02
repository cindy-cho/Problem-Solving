#include<iostream>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, H, W, N,XX,YY;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> H >> W >> N;
        YY = N/H;
        XX = N%H;
        if(XX==0) XX = H;
        else YY++;

        if(YY<10) XX*=10;
        cout << XX << YY << endl;
    }
    return 0;
}