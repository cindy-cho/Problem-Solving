#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    
    int i;
    cin >> N >> M;
    vector <int> A(N+M);
    
    for(i=0;i<N+M;i++) cin >> A[i];
    sort(A.begin(),A.end());
    for(auto aa:A) cout << aa << " ";
    cout << "\n";
    


    return 0;
}