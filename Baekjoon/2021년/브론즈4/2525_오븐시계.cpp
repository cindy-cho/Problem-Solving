#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A,B,C;
    cin >> A >> B >> C;
    A = A*60 + B + C;
    B = A % 60;
    A = A/60;
    if(A>23) A-=24;
    cout << A << " " << B << "\n";
    return 0;
}