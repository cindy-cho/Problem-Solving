#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define endl '\n'
typedef long long ll;

using namespace std;
int m;
bool cmp(pair<string,int> A, pair<string,int> B){
    for(int i=0;i<m;i++){
        if(A.first[i] == B.first[i]) continue;
        if(i%2==0){ // desc
            return A.first[i] < B.first[i];
        }
        return A.first[i] > B.first[i];
    }
    return A.first < B.first;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> m;
    vector<pair<string,int>> book(n);
    for(int i=0;i<n;i++){
        cin >> book[i].first;
        book[i].second = i+1;
    }
    sort(book.begin(),book.end(),cmp);
    for(int i=0;i<n;i++) cout << book[i].second << " ";
    cout << endl;
    return 0;
}