#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr[1000],lis[1000],i,j,ans=0;
    int N;
    cin >> N;
    lis[0]=1;
    for(i=0;i<N;i++){
        cin >> arr[i];
        lis[i]=0;
        for(j=0;j<i;j++){
            if(arr[j] < arr[i] && lis[j]>lis[i]) lis[i]=lis[j];
        }
        lis[i]+=1;
        if(lis[i] > ans) ans=lis[i];
    }

    cout << ans << "\n";
    return 0;
}