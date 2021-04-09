#include<iostream>
#include <stack>
using namespace std;

int main(void){
    int n;
    stack <int> s;
    
    cin >> n;
    if(n==0) cout << "0\n";
   else{
    while(n!=1){
        if(n<0){
            n=n* (-1);
            s.push(n%2);
            n = n/2 + n%2;
        }
        else{
            s.push(n%2);
            n = (n/2) * (-1); 
        }
    }
    s.push(n);

    while(!s.empty()){
        cout << s.top();
        s.pop();
    }}
    return 0; 
}

