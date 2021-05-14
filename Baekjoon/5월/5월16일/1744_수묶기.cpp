#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,s,e,i;
    long long sum = 0;
    cin >> N;
    vector<long long> arr(N);
    for(i=0;i<N;i++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    
    s=0; e=N-1;
    while(s<N && arr[s]<0){
        if(s+1<N && arr[s]<0 && arr[s+1]<=0){
            sum += (arr[s]*arr[s+1]);
            s+=2;
        }
        else{
            sum += arr[s];
            s++;
        }
    }
    while(e>=0 && arr[e]>0){
        if(arr[e]==1){
            sum += arr[e];
            e--;
        }
        else if(e-1>=0 && arr[e]>1 && arr[e-1]>1){
            sum += (arr[e]*arr[e-1]);
            e-=2;
        }
        else{
            sum += arr[e];
            e--;
        }
    }

    cout << sum << "\n";
    return 0;
}