#include<iostream>
using namespace std;
long long int arr[10];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T,n,i,j,k;
    long long int ans;
    arr[0]=1;
    ans = 0; cin >> n;
    for(j=1;j<=n;j++){
        for(k=1;k<10;k++){
            if(j==1) arr[k]=1;
            else {
                arr[k]=arr[k-1]+arr[k];
                if(j%10==0) arr[k]%=10007;
            }

    }}
    for(k=0;k<10;k++) ans+=arr[k];
    cout << ans%10007 << "\n";
   
    return 0;
}