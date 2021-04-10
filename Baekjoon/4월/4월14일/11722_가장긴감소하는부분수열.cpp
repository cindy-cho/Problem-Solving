#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A,answer=1,max;
    cin >> A;
    vector <int> arr(A);
    vector <int> ans(A);
    for(int i=0;i<A;i++){
        cin >> arr[i];
    }
    ans[0]=1;
    for(int i=1;i<A;i++){
        max=0;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[i] && max<ans[j]) max = ans[j];
        }
        ans[i]=max+1;
        if(ans[i]>answer) answer =ans[i];
    }
    
    cout << answer << "\n";
    return 0;
}