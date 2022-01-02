#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int UR,TR,UO,TO;
    cin >> UR >> TR >> UO >> TO;
    cout << 56*UR + 24*TR + 14*UO + 6*TO << "\n";
    return 0;
}