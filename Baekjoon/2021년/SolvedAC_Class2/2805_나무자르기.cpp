#include<iostream>
#include<vector>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N,M,start,end,mid,cut,answer;
    cin >> N >> M;
    vector<ll> tree(N);
    for(ll i = 0; i< N ; i++) cin >> tree[i];
    start = 0;
    end = 1000000000;
    while(start<=end){
        mid = (end-start)/2+start;
        cut = 0 ;
        for(ll i =0; i<N; i++){
            if(tree[i] <= mid) continue;
            else  cut += tree[i] - mid;
        }
        if( cut < M ){
            
            end = mid - 1;
        }
        else {
            answer = mid;
            start = mid + 1;
        }
    }
    cout << answer << endl;
    return 0;
}