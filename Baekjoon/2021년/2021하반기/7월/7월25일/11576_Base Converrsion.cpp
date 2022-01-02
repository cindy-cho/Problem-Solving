#include<iostream>
#include<stack>
#include<math.h>
#define endl '\n'
typedef long long ll;


using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll A, B;
    ll num=0;
    ll unit;
    cin >> A >> B;
    ll m;
    cin >> m;
    stack<int> answer;
    for(int i=m-1;i>=0;i--){
        cin >> unit;
        num+= unit*pow(A,i);
    }
    
    while(num>0){
        answer.push(num%B);
        num = num / B;
    }

    while(!answer.empty()){
        cout << answer.top() << " ";
        answer.pop();
    }
    return 0;
}