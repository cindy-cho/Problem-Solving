#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A,ans=0;
    vector<int> left(42,0);
    for(int i=0;i<10;i++){
        cin >> A;
        if(left[A%42]==0){
            left[A%42]=1;
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}