#include<iostream>
#include<string>
#include<math.h>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    
    ll answer = 0;
    ll unit=0, num;
    string target;
    
    cin >> N >> target;
    int tLen = target.length();
    for(int i=tLen;i<N;i++){
        target+= '0';
    }

    for(int i=N-1;i>=0;i--){
        unit = unit*26 + 1;
        if(target[i]=='0') num = 0;
        else num = target[i]-'a';
        if(target[i]!='0') answer++;
        answer += num*unit;
    }
    
    cout << answer << endl;
    return 0;
}