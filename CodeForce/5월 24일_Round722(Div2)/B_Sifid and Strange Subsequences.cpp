#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n,start,end,j;
    double arr[100000],max;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        for(j=0;j<n;j++){
            cin >> arr[j];
        }
        sort(arr,arr+n);
        if(arr[n-1]==0 || n==1 ){
            cout << n << "\n";
        }
        else if(arr[0]>0){
            cout << "1\n";
        }
        else if(arr[0]==0){
            for(j=0;j<n;j++) if(arr[j]!=0) break;
            cout << j << "\n";
        }
        else{
            start = 0;
            end = n-1;
            while(start<end){
                if(arr[start+1]-arr[start] >= arr[end]){
                    start++;
                }
                else end--;
            }
            cout << end+1 << "\n";
        }
    }
    return 0;
}