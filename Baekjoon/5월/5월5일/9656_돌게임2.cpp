#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    if(N%4==1 || N%4==3) cout << "CY\n";
    else cout  << "SK\n";
    return 0;
}