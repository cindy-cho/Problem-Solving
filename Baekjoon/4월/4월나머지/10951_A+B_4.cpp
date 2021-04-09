#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A, B;
    cin >> A >> B;
    while(!cin.eof()){
        cout << A+B << "\n";
        cin >> A >> B;
    }
    return 0;
}