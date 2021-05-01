#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A,ANS=0;
    for(int i=0;i<4;i++){
        cin >> A;
        ANS += A;
    }
    cout << ANS/60 << "\n";
    cout << ANS%60 << "\n";
    return 0;
}