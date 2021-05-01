#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,ANS=0;
    cin >> n >> k;
    ANS = n*k;
    cin >> n >> k;
    ANS += n*k;
    cout << ANS << "\n";
    return 0;
}