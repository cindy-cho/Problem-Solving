#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n,l,r,s;
    int count,target;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n >> l >> r >> s;
        count = r-l+1;
        target=0;
        vector<int> arr(n+1,0);
        for(int j=1;j<=n;j++){
            target += j;
            arr[j]=1;
            if(s-target <=n){
                arr[s-target]=1;
                break;
            }
            if(target+(n-j+1)<=s){
                arr[n-j+1]=1;
                target += (n-j+1);
            }
        }
    }
    return 0;
}