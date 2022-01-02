#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,ans,sum,cpy,cnt=0,i;
    cin >> N;
    cpy = N;
    while(cpy>0){
        cnt++;
        cpy /= 10;
    }
    for(i=N-9*(cnt+1);i<N;i++){
        cpy = i;
        sum = cpy;
        while(cpy>0){
            sum += cpy%10;
            cpy/=10;
        }
        if(sum==N) break;
    }
    if(i==N) cout << "0\n";
    else cout << i << "\n";
    return 0;
}