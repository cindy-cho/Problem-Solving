#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,T,C,P;
    cin >> N >> T >> C >> P;
    cout << ((N-1)/T) * C * P << "\n";
    return 0;
}