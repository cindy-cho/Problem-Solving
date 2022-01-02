#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int L,A,B,C,D;
    cin >> L >> A >> B >> C >> D;
    if(A%C!=0){
        A=A/C+1;
    }
    else A=A/C;
    if(B%D!=0){
        B=B/D+1;
    }
    else B=B/D;
    if(A<B) A=B;
    cout << L-A <<"\n";
    return 0;
}