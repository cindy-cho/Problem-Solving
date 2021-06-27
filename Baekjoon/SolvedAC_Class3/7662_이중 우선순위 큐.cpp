#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
#define endl '\n'
typedef long long ll;

using namespace std;

struct mCmp{
    bool operator()(ll A, ll B){
        return A > B;
    }
};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T,k,num;
    char op;

    cin >> T;
    for(int i=0;i<T;i++){
        cin  >> k;
        priority_queue <ll, vector<ll>, mCmp> minq;
        priority_queue <ll> maxq;
        map<ll,int> nums;
        for(int j=0;j<k;j++){
            cin >> op >> num ;
            if(op=='I'){
                minq.push(num);
                maxq.push(num);
                if(nums.find(num)!=nums.end()) nums[num]++;
                else nums[num]=1;
            }
            else{
                if(num==1){
                    while(!maxq.empty()){
                        if(nums[maxq.top()]!=0){
                            nums[maxq.top()]--;
                            maxq.pop();
                            break;
                        }
                        maxq.pop();
                    }
                    if(maxq.empty()){
                        while(!minq.empty()) minq.pop();
                    }
                }
                else{
                    while(!minq.empty()){
                        if(nums[minq.top()]!=0){
                            nums[minq.top()]--;
                            minq.pop();
                            break;
                        }
                        minq.pop();
                    }
                    if(minq.empty()){
                        while(!maxq.empty()) maxq.pop();
                    }
                }
            }
        }
        while(!maxq.empty()){
                if(nums[maxq.top()]==0) maxq.pop();
                else break;
        }
        while(!minq.empty()){
            if(nums[minq.top()]==0) minq.pop();
            else break;
        }
        if(minq.empty() || maxq.empty()){
            cout << "EMPTY" << endl;
        }
        else{
            cout << maxq.top() << " " << minq.top() << endl;
        }
    }
    return 0;
}