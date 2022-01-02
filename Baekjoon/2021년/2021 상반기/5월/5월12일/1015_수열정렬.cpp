#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int,int> A, pair<int,int> B){
    if(A.first == B.first) return  A.second < B.second;
    return A.first < B.first ;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<int,int>> A(N);
    vector<int> P(N);
    for(int i=0;i<N;i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(),A.end(),cmp);
    for(int i=0;i<N;i++){
        P[A[i].second] = i;
    }
    for(int i=0;i<N;i++)   cout << P[i] << " ";


    return 0;
}