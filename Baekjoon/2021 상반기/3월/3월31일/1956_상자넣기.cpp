
#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,i,j,val,m=0,cnt=0,ans=0;
    cin >> n;
    int boxes[1001];
    int LIS[1001];
    for(i=0;i<n;i++){
        cin >> val;
        boxes[i]=val;
       
       
        if(i==0) LIS[i]=1;
        else{
            m=0;
            for(j=i-1;j>=0;j--){
                if(val>boxes[j] && LIS[j]>m){
                    m=LIS[j];
                }
            }
            LIS[i]=m+1;
            if(ans<LIS[i]) ans = LIS[i];
        }
    }
    // for(i=0;i<n;i++) cout << LIS[i] << ",";
    // cout << "\n";
    cout << ans << "\n";
    return 0;
}