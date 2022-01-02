#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int K,N;
    cin >> K >> N;
    vector<long long int> line(K);
    long long int crnt;
    long long int start,end=0,mid,ans;
    for(int i=0;i<K;i++){
        cin >> line[i];
        if(line[i]>end) end = line[i];
    }
    start = 1;
    while(start<=end){
        crnt = 0;
        mid = start + (end-start)/2;
        for(int i=0;i<K;i++){
            crnt+= line[i]/mid;
        }
        if(crnt>=N) {
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

    cout << ans << "\n";
    return 0;
}