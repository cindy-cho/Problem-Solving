#include<iostream>
#include<vector>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int row, col, paper, wrong, pR, pC;
    cin >> row >> col >> paper >> wrong;
    vector<ll, ll> arr(wrong);
    for(int i=0;i<wrong;i++) cin >> arr[i].first >> arr[i].second ;
    return 0;
}