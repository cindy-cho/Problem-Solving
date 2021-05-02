#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,Kim,Lim,count=0;
    cin >> N >> Kim >> Lim;
    while(Kim!=Lim){
        count++;
        Kim= Kim/2+Kim%2;
        Lim= Lim/2+Lim%2;
    }
    cout << count << "\n";
    return 0;
}
