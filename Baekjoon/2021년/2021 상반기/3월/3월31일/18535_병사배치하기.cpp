#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int arr[2000],lis[2000],i,j,ans=0;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> arr[i];
        lis[i]=0;
        for(j=0;j<i;j++){
            if(arr[j] > arr[i] && lis[j] > lis[i]) lis[i]=lis[j];
        }
        lis[i]+=1;
        if(lis[i] > ans) ans = lis[i];
    }
    cout << N-ans << "\n";
    return 0;
}