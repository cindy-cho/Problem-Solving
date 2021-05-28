#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int N,start,end,mid,ans;
    cin >> N;
    start = 1;
    end = N;
    while(start<=end){
        mid = start + (end-start)/2;
        if (mid <= N/mid) {
            ans = mid;
            start = mid+1;
        }
        else end = mid - 1;
    }

    cout << ans << "\n";
    return 0;
}