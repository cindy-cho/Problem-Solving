#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A=0,B=0,x;
    for(int i=0;i<4;i++){
        cin >> x;
        A+=x;
    }
    for(int i=0;i<4;i++){
        cin >> x;
        B+=x;
    }
    if(A>B) cout << A << "\n";
    else cout << B << "\n";
    return 0;
}