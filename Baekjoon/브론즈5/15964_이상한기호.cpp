#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long A,B;
    cin >> A >> B;
    cout << (A+B)*(A-B) << "\n";
    return 0;
}