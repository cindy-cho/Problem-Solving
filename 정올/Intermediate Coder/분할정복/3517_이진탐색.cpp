#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,Q,start,end,mid,target;
    cin >> N;
    vector<int> arr(N);
    for(int i=0;i<N;i++) cin >> arr[i];
    cin >> Q;
    for(int i=0;i<Q;i++) {
        cin >> target;
        if(target<arr[0] || target>arr[N-1]) cout << "-1 ";
        else{
            start = 0;
            end = N-1;
            while(start<=end){
                mid = (end-start)/2 + start;
                if(arr[mid]==target) break;
                if(arr[mid]>target) end = mid-1;
                else start = mid+1;
            }
            if(arr[mid]==target) cout << mid << " ";
            else cout << "-1 ";
        }
    }
}