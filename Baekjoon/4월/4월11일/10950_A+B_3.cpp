#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,A,B;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A >> B;
        cout << A+B << "\n";
    }
    return 0;
}