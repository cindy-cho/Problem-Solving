#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    if(N%5!=0) cout << N/5+1 << "\n";
    else cout << N/5 << "\n";
    return 0;
}