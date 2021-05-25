#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n,j;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        vector<int> arr(n);
        for(j=0;j<n;j++)
            cin >> arr[j];
        sort(arr.begin(),arr.end());
        for(j=0;j<n-1;j++)
            if(arr[j+1]>arr[j]) break;
        cout << n-j-1 << "\n";    
    }
    return 0;
}