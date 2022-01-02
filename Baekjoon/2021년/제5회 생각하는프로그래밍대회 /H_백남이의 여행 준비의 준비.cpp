#include<iostream>
#include<numeric>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    int A,B,C,a,b,c;
    int Target;
    int TA,TB,TC;
    int ans;
    cin >> T;
    for(int i=0;i<T;i++){
        cin>> A >> B >> C >> a >> b >> c;
        Target = lcm(A,B);
        cout << Target << " , " ;
        Target = lcm(Target, C);
        cout << Target << endl;
        // TA = (Target+a)%A;
        // TB = (Target+b)%B;
        // TC = (Target+c)%C;
        // if(TA==a && TB==b && TC==c) cout << Target << endl;
        // else cout << "-1\n";
    }
    return 0;
}