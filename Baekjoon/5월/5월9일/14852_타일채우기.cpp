#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long N;
    long long prev2=2,prev=7,now,sum=0;
    cin >> N;
    if(N==1){
        cout << prev2 << "\n";
        return 0;
    }
    if(N==2){
        cout << prev << "\n";
        return 0;
    }
    sum = prev2+prev;
    for(int i=3;i<=N;i++){
        now = (sum*2+prev2)%1000000007;
        sum += now;
        sum %= 1000000007;
        prev2=prev%1000000007;
        prev=now%1000000007;
    }


    cout << now << "\n";
    return 0;
}