#include<iostream>
#include<vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,i,K;
    long long sum=0,max=0,cur;
    vector<int> arr(N);
    cin >> N >> K;
    for(i=0;i<K;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    max = sum;
    for(;i<N;i++){
        cin >> arr[i];
        cur = sum-arr[i-K]+arr[i];
        if( cur > max){
            max = cur;
        }
        sum = cur;
    }

    cout << max << "\n";
    return 0;
}