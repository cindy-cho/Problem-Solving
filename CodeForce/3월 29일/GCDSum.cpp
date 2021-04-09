#include<iostream>
#include<math.h>
using namespace std;
long long int n;
void gcdSum(){
    long long int sum=0,tmp;
    int i;
    tmp = n;
    while(tmp>0){
        sum+=tmp%10;
        tmp/=10;
    }
    if(sum==1){
        n++;
        gcdSum();
    }
    else if(n%sum==0) return;
    else{
        for(i=2;i<=sqrt(sum);i++){
            if(sum%i==0){
                if(n%i==0 || n%(sum/i)==0) return;
            }
        }
        n++;
        gcdSum();
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,i,j,flag;

    cin >> t;
    for(i=0;i<t;i++){
        cin >> n;
        gcdSum();
        cout << n << "\n";
    }
    return 0;
}