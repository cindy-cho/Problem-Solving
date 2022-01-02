#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string A,B;
    int AA,BB;
    cin >>A >> B;
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    AA = stoi(A);
    BB = stoi(B);
    if(AA>BB) cout << AA << "\n";
    else cout << BB << "\n";
    return 0;
}