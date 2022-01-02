#include <iostream>

using namespace std;

int main(void){
    long long N,P,i;
    long long ans =1;
    for(int j=0;j<10;j++){
    cin >> N >> P;
    if(N==1) cout << "1\n" ;
    else{
        ans = N;
        for(i=N-1;i>=1;i--){
            ans = (ans*i)%P;
        }
        cout  << ans << "\n";
    }}
    return 0;
}