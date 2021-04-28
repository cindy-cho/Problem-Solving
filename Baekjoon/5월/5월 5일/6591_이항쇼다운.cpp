#include<iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long int n,k,ans,i,m;

    cin >> n >> k;
    while(1){
        if(n==0 && k==0) return 0;
        if(k==0 || k==n) cout << "1\n";
        else{
            ans = 1;
            m = 1;
            if(n-k > k) k = n-k;
            for(i = n;i>=k+1;i--){
                ans = ans * i;
                while(m<=n-k && ans%m==0){
                    ans /= m;
                    m++;
                }
            }
            // for(i=1;i<=n-k;i++){
            //     ans = ans / i;
            // }

            cout << ans << "\n";
        }
        cin >> n >> k;
        
    }
    return 0;
}