#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int A;
    long long int len=0;
    long long int idx;
    cin >> A;
    vector < long long int > arr(A);
    vector < long long int > newArr;
    for(long long int i=0;i<A;i++){
        cin >> arr[i];
    }
    newArr.push_back(arr[0]);
    for(long long int i=1;i<A;i++){
        if(arr[i]>newArr[len]){
            newArr.push_back(arr[i]);
            len++;
        }
        else{
            idx = upper_bound(newArr.begin(),newArr.end(),arr[i])-newArr.begin();
            if(idx!=0 && newArr[idx-1]==arr[i]) continue;
            newArr[idx] = arr[i];
        }
    }

    cout << len+1 << "\n";

    
    return 0;
}