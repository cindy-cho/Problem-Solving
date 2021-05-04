#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int now,prev;
    int dir;
    cin >> prev >> now;
    dir = now - prev;
    prev = now;
    for(int i=2;i<8;i++){
        cin  >> now;
        if(now-prev!=dir) {
            cout << "mixed\n";
            return 0;
        }
        dir = now - prev;
        prev = now;
    }
    if(dir==1) cout << "ascending\n";
    else cout << "descending\n";
    return 0;
}