#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,X,val;
    cin >> N >> X;
    for(int i=0;i<N;i++){
        cin >> val;
        if(val< X) cout << val <<  " ";
    }
    
    return 0;
}