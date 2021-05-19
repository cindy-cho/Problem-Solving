#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A,B,C,D,E;
    cin >> A >> B >> C >> D >> E;
    A = min(A,min(B,C));
    D = min(D,E);
    cout << A + D -50 << "\n";
    return 0;
}