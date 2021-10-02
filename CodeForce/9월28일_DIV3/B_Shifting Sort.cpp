#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,l,r,n,k; //  1 <= l < r <= n
    bool isSorted;
    int targetIdx; // shift to left
    cin >> t;
    ll tmp;
    for(int tc=0;tc<t;tc++){
        isSorted=true;
        k=0; //(number of actions)
        cin >> n;
        vector<ll> arr(n),cpy(n);
        vector<vector<int>> ans(n, vector<int> (3));
        for(int i=0;i<n;i++) {
            cin >> arr[i];
            cpy[i] = arr[i];
            if(i>0 && arr[i]<arr[i-1]) isSorted = false;
        }
        
        if(isSorted==true){
            cout << k << endl;
            continue;
        }
        sort(cpy.begin(),cpy.end());
        targetIdx = 0;
        r=0;
        l=0;

        for(int i=0;i<n;i++){

            while(l<n && targetIdx<n && arr[l]==cpy[targetIdx]){
                l++;
                targetIdx++;
            }

            if(l==n) {
                break;
            }
            for(r=l+1;r<n;r++){
                if(arr[r]==cpy[targetIdx]) {
                    break;
                }
            }
            for(int j=r; j>l;j--) arr[j] = arr[j-1];
            arr[l] = cpy[targetIdx];
            ans[k][0] = l+1;
            ans[k][1] = r+1;
            ans[k][2] = r-l;
            l++;
            targetIdx++;
            k++;
        }
        cout << k << endl;
        for(int i=0;i<k;i++){
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
        }

    }
    
    return 0;
}