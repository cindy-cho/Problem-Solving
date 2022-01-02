#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,ANS=0;
    for(int j=0;j<5;j++){
        cin >> i;
        ANS = (ANS + i*i) % 10;
    }
    cout << ANS << "\n";
    return 0;
}