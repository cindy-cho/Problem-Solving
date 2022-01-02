#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A,SUM=0;
    for(int i=0;i<6;i++){
        cin >> A;
        SUM +=A;
    }
    cout << SUM*5 << endl;
    return 0;
}