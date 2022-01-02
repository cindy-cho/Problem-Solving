#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long  A,B,C,D;
    cin >> A >> B >> C >> D;
    A = A*3600+B*60+C+D;
    C = A % 60;
    B = A / 60 % 60;
    A = A / 3600;
    A %= 24;
    cout << A << " " << B << " " << C << "\n";
    return 0;
}