#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int sum =0;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i=0;i<N;i++) cin >> A[i] ;
    for(int i=0;i<N;i++) {
        cin >> B[i] ;
    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),cmp);
    for(int i=0;i<N;i++) sum += A[i]*B[i];
    cout << sum << "\n";
    return 0;
}