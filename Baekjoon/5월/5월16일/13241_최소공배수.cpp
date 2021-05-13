#include<iostream>
#include<numeric>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int A,B;
    cin >> A >> B;
    cout << lcm(A,B) << "\n";
    return 0;
}