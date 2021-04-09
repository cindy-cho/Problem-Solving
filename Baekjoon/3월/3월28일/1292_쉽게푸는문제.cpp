#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A,B;
    int idx=1;
    int sum=0;
    int i,T=1;
    cin >> A >> B;
    while(1){
        for(i=1;i<=T;i++) {
            if(idx>=A && idx<=B) {
                // cout << idx << "," << T << "," << sum << endl;
                sum+=T;
            }
            if(idx>B) break;
            idx++;
        }
        if(idx>B) break;
        T++;
        
    }
    cout << sum << endl;

    return 0;
}

