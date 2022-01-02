#include<iostream>
#include<string>
#include<stack>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string inLine;
    int len,flag;
    stack <char> s;
    while(1){
        getline(cin, inLine);
        if(inLine[0]=='.' && inLine.length()==1) break;
        len = inLine.length();
        flag = 0;
        for(int i=0;i<len;i++){
            if(inLine[i]=='(') s.push('(');
            else if(inLine[i]=='[') s.push('[');
            else if(inLine[i]==')'){
                if(!s.empty() && s.top()=='(') s.pop();
                else{
                    flag = 1;
                    break;
                }
            }
            else if(inLine[i]==']'){
                if(!s.empty() && s.top()=='[') s.pop();
                else{
                    flag = 1;
                    break;
                }
            }
        }
        if(flag==1 || !s.empty()) cout << "no" << endl;
        else cout << "yes" << endl;
        while(!s.empty()) s.pop();
    }
    return 0;
}