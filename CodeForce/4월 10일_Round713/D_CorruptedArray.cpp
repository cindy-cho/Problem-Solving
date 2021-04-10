#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n,val,sum;
    int ansFlag,tar1,tar2;

    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        sum = 0;
        ansFlag = -1;
        vector<int> arr(n+2);
        for(int j=0;j<n+2;j++) {
            cin >> arr[j];
            sum += arr[j];
        }
        sort(arr.begin(),arr.end());
        for(int j=0;j<n+1;j++){
            if(sum-arr[n+1]-arr[n+1]==arr[j]){
                ansFlag=1;
                tar1=n+1;
                tar2=j;
                break;
            }
        }
        if(ansFlag==-1 && sum - arr[n] - arr[n] == arr[n+1]){
            tar1=n;
            tar2=n+1;
            ansFlag=1;
        }

        if(ansFlag==-1){
            cout << "-1\n";
        }
        else{
            for(int j=0;j<n+2;j++){
                if(j==tar1 || j==tar2) continue;
                else cout << arr[j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}