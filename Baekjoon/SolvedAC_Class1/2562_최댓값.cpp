#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A,M=0,idx;
    for(int i=0;i<9;i++){
        cin >> A;
        if(A>M) {
            M=A;
            idx = i+1;
        }
    }
    cout << M << "\n" << idx << "\n";
    return 0;
}