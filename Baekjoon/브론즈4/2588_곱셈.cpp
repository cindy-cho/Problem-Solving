#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long A,B;
    int B1,B2,B3;
    cin >> A >> B;
    B3 = B%10;
    B2 = (B/10)%10;
    B1 = B/100;
    cout << A*B3 << "\n" << A*B2 << "\n" << A*B1 << "\n" << A*B << "\n";
    return 0;
}