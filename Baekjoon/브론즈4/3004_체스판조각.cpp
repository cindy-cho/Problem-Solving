#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,A,B;
    cin >> N;
    A = N/2;
    B = N/2+N%2;
    A++; B++;
    cout << A*B << "\n";
    return 0;
}