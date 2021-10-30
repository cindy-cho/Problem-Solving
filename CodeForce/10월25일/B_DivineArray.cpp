#include<iostream>
#include <numeric>
#include<vector>
#include<map>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    int n;
    cin >> tc;
    while(tc--){
        cin >> n;
        vector<int> a(n);
        map<int,int> count;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(count.find(a[i])==count.end()){
                count.insert({a[i],1});
            }
            else count[a[i]] ++;
        }
    }
    return 0;
}

