#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A[3],B[3],C[3];
    for(int i=0;i<3;i++) cin >>A[i];
    for(int i=0;i<3;i++) cin >>C[i];
    B[0] = C[0]-A[2];
    B[1] = C[1]/A[1];
    B[2] = C[2]-A[0];
    for(int i=0;i<3;i++) cout << B[i] << " ";
    cout << "\n";
    return 0;
}