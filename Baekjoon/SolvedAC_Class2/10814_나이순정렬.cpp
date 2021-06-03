#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define endl '\n'
typedef long long ll;

using namespace std;

typedef struct{
    int birth;
    int join;
    string name;
} memberInfo;
bool cmp(memberInfo A, memberInfo B){
    if(A.birth==B.birth) return A.join < B.join;
    return A.birth < B.birth;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<memberInfo> member(N);
    for(int i=0;i<N;i++) {
        cin >> member[i].birth >> member[i].name;
        member[i].join = i;
    }

    sort(member.begin(),member.end(),cmp);
    for(int i=0;i<N;i++) cout << member[i].birth << " " << member[i].name << endl;
    
    return 0;
}