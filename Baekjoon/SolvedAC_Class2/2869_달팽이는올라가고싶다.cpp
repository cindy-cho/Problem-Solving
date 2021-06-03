#include<iostream>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int A,B,V,day=0;
    cin >> A >> B >> V;
    day = (V-A) / (A-B);
    if((V-A)%(A-B)!=0) day++;
    cout << day+1 << endl;
    return 0;
}