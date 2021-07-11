#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int  ans=0;
    string input;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> input;
        stack<char> s;
        for(auto i:input){
            if(s.empty()) s.push(i);
            else if(s.top()==i){
                s.pop();
            }
            else s.push(i);
        }
        if(s.empty()) ans++;
    }
    cout << ans << "\n";
    return 0;
}