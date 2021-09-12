#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int smaller=0,bigger=0,full=0;
    int answer = 0;

    ll X,hairTmp;
    cin  >> N >> X;
    for(int i=0;i<N;i++){
        cin >> hairTmp;
        if(hairTmp==X) full++;
        else if(hairTmp*2 >=X) bigger++;
        else smaller++;
    }
    answer = full;
    if(bigger==0 && smaller == 0){
        cout << answer << endl;
        return 0;
    }
    if(bigger == smaller){
        cout << answer + bigger << endl;
        return 0;
    }
    if(bigger < smaller){
        answer += bigger;
        smaller -= bigger;
        answer += smaller / 3;
        cout << answer << endl;
        return 0;
    }
    answer += smaller;
    bigger -= smaller;
    answer += bigger / 2;
    cout << answer << endl;
    return 0;
}
