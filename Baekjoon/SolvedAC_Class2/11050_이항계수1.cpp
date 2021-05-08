#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,K,mul=1;
    int a,b,c;
    /*
    이항계수 : (n m) = n! / m!(n-m)!
    */
    cin >> N >> K;
    if(K==0 || K==N) {
        cout << "1\n";
        return 0;
    }
    for(int i=1;i<=N;i++){
        mul*=i;
        if(i==N) a=mul;
        if(i==K) b=mul;
        if(i==N-K) c=mul;
    }
    cout << a / (b*c) << "\n";
    return 0;
}