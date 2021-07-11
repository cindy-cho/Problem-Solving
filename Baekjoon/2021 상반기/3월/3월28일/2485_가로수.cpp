#include<iostream>
#include <numeric>
#include<vector>
#include<algorithm>
using namespace std;

long long gcd(long long a, long long b){
    long long tmp;
    if(b>a){
        tmp=a;
        a=b;
        b=tmp;
    }
    while(b!=0){
        tmp = a%b;
        a=b;
        b=tmp;
    }
    return a;
}
int main(void){
    long long N,jump=0;
    int answer=0;
    long long i,preval=0,val;
    
    cin >> N;
    vector <long long > tree(N);
    
    for(i=0;i<N;i++){
        cin >> val;
        tree[i]=val;
    }
    sort(tree.begin(),tree.end());
    jump = tree[1]-tree[0];
    for(i=2;i<N;i++){
        val=tree[i]-tree[i-1];
        jump = gcd(jump,val);
    }
    for(i=1;i<N;i++){
        answer += (tree[i]-tree[i-1])/jump-1;
    }
    cout << answer << "\n";
    return 0;
}