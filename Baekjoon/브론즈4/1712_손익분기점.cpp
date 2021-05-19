#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A,B,C;
    int N;
    cin >> A >> B >> C;
    if(C-B==0) N = -1;
    else{
        N = A / (C-B);
        N++;
        if(N<0) N = -1;
    }
    cout << N << endl;
    return 0;
}