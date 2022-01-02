#include<iostream>
#include<stack>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int K;
    int now;
    stack<int> s;
    long long sum=0;
    cin >> K;
    for(int i=0;i<K;i++){
        cin >> now;
        if(now!=0) {
            sum+=now;
            s.push(now);
        }
        else{
            sum -= s.top();
            s.pop();
        }
    }

    cout << sum << "\n";
    return 0;
}