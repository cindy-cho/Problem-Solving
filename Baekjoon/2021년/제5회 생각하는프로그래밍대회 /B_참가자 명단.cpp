#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define endl '\n'
typedef long long ll;

using namespace std;

bool compare(string A, string B){
    if(A.length()==B.length()){
        return A < B;
    }
    return A.length() < B.length();
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    int room;
    string name;
    cin >> N >> M;
    cin >> room >> name;
    vector<int> signUp(N,0); //신청자 수 학급별 저장
    vector<vector<string>> names(N,vector<string> (M));
    //홀수 - 청, 짝수 - 백
    while(room!=0 && name!="0"){
        room--;
        if(signUp[room]<M){
            names[room][signUp[room]]=name;
            signUp[room]++;
        }
        cin >> room >> name;
    }

    for(int i=0;i<N;i++){
        sort(names[i].begin(),names[i].begin()+signUp[i],compare);
        if((i+1)%2==1){
            for(int j=0;j<signUp[i];j++){
                cout << i+1 << " " << names[i][j] << endl;
            }
        }
    }
    for(int i=0;i<N;i++){
        if((i+1)%2==0){
            for(int j=0;j<signUp[i];j++){
                cout << i+1 << " " << names[i][j] << endl;
            }

        }
    }
    return 0;
}