#include<iostream>
#include<numeric>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int a,b;
    for(int i=0;i<N;i++){
        cin >> a >> b;
        cout << lcm(a,b) << "\n";
    }
    return 0;
}