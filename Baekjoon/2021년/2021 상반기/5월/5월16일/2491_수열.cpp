#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,A;
    int inc=1,incMax=1,dec=1,decMax=1;
    cin >> N;
    vector<int> arr(N);
    cin >> arr[0];
    for(int i=1;i<N;i++){
        cin >> arr[i];
        if(arr[i]>=arr[i-1]) inc++;
        else{
            if(incMax<inc) incMax = inc;
            inc = 1;
        }
        if(arr[i]<=arr[i-1]) dec++;
        else{
            if(decMax<dec) decMax = dec;
            dec = 1;
        }
    }
    if(incMax<inc) incMax = inc;
    if(decMax<dec) decMax = dec;
    // if(max(incMax,decMax)<3) cout << "2\n";
    // else 
    cout << max(incMax,decMax) << "\n";
    return 0;
}