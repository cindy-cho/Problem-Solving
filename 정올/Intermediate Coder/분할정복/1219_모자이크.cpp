#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
typedef long long ll;

using namespace std;

bool cmp(pair<ll,ll> A, pair<ll, ll> B){
    if(A.second == B.second) return A.first < B.first;
    return A.second < B.second;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int row, col, paper, wrongColor, cnt, stand,idx;
    long long start=0,end=1000000,mid,ans=0;
    cin >> row >> col >> paper >> wrongColor;
    vector<pair<ll, ll>> arr(wrongColor);
    for(int i=0;i<wrongColor;i++) {
        cin >> arr[i].first >> arr[i].second ;
        if(start < arr[i].first) start = arr[i].first;
    }

    // cout << "Start , End : " << start << "," << end << endl;
    sort(arr.begin(), arr.end(),cmp);
    // for(int i=0;i<wrongColor;i++) cout << arr[i].second << "," << arr[i].first << endl;
    if(wrongColor==0){
        cout << "0\n";
        return 0;
    }
    while(start<=end){
        mid = (start+end)/2;
        cnt = 0;
        stand = arr[0].second;
        idx = 0;
        while(idx < wrongColor){
            cnt++;
            while(arr[idx].second<stand+mid){
                idx++;
                if(idx == wrongColor) break;
            }
            if(idx == wrongColor) break;
            stand = arr[idx].second;
        }
        if(cnt>paper)start = mid+1;
        else {
            ans = mid;
            end = mid-1;
        }
    }
    cout << ans << endl;
    return 0;
}