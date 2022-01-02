#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double N;
    cin >> N;
    cout << (int)(N*0.78) << " " << (int)(N*0.8+N*0.2*0.78) << "\n";
    return 0;
}