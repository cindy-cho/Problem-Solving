#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int L, P;
    cin >> L >> P;
    L *= P;
    for(int i=0;i<5;i++){
        cin >> P;
        cout << P-L << " ";
    }
    return 0;
}