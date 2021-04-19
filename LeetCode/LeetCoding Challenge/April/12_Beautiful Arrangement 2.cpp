// Example 1:

// Input: n = 3, k = 1
// Output: [1, 2, 3]
// Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
// Example 2:

// Input: n = 3, k = 2
// Output: [1, 3, 2]
// Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.

#include<iostream>
#include<vector>
using namespace std;

/* 
k==1
1 2 3
1+1, 2+1
k==2
1 1+2 3-1
k==2
1 1+2 3-1 2+2 4+1

(5,4)
1 5 2 4 3

*/
class Solution {
public:
    vector<int> constructArray(int n, int k){
        vector<int> ans(n);
        vector<int> vst(n,false);
        int idx=0;
        int dir=1;
        ans[0]=1;
        vst[0]=true;
        if(k==1){
            for(int i=1;i<n;i++) ans[i]=ans[i-1]+1;
            return ans;
        }
        for(int i=1;i<n;i++){
            if(vst[ans[idx]+k*dir-1]==true) dir*=-1;
            ans[idx+1]=ans[idx]+(k*dir);
            vst[ans[idx]+(k*dir)-1]=true;
            idx++;
            dir*=-1;
            k+=dir;
        }
        return ans;
    }
};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector <int> ans;
    Solution S;
    ans = S.constructArray(5,4);
    for(auto a : ans){
        cout << a << " ";
    }

    return 0;

}