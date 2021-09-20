#include<iostream>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==0 || i==N-1 || j==0 || j==N-1) cout << "*";
            else if(i==j || j==N-i-1) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
    return 0;
}