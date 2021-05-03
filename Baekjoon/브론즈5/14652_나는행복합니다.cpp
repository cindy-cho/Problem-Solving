#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M,W;
    cin >> N >> M >> W; //세로, 가로
    cout << W/M << " " << W%M << "\n";
    return 0;
}