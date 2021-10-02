#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<algorithm>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int totalSum=0;
    cin >> N;
    vector<int> nums(N);
    set<int> candidate;
    stack<int> st;
    for(int i=0;i<N;i++) {
        cin >> nums[i];
        totalSum+=nums[i];
    }
    sort(nums.begin(),nums.end());
    candidate.insert(0);
    for(int i=0;i<N;i++){
        for(auto it : candidate){
            st.push(it+nums[i]);
        }
        while(!st.empty()){
            candidate.insert(st.top());
            st.pop();
        }
    }
    // for(auto it : candidate){
    //     cout << it << " / " ;
    // }
    // cout << candidate.size() << endl;
    cout<< totalSum - candidate.size() + 1<< endl;
}
