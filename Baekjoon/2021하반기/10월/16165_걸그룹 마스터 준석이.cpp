#include<vector>
#include <string>
#include<iostream>
#include<algorithm>
#define endl '\n'
typedef long long ll;

using namespace std;
typedef struct{
    string groupName;
    int member;
    vector<string> name;
}GIRLGROUP;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    bool isAnswer;
    cin >> N >> M;
    vector<GIRLGROUP> G(N);
    for(int i=0;i<N;i++){
        cin >> G[i].groupName >> G[i].member;
        G[i].name.resize(G[i].member);
        for(int j=0;j<G[i].member;j++) cin >> G[i].name[j];
        sort(G[i].name.begin(),G[i].name.end());
    }

    string findName;
    int quizType;
    for(int i=0;i<M;i++){
        cin >> findName >> quizType;
        if(quizType == 0) { // girl names
            for(int j=0;j<N;j++){
                if(G[j].groupName == findName){
                    for(int k=0;k<G[j].member;k++){
                        cout << G[j].name[k] << endl;
                    }
                }
            }
        }
        else{
            isAnswer = false;
            for(int j=0;j<N;j++){
                for(int k=0;k<G[j].member;k++){
                    if(G[j].name[k]==findName){
                        cout << G[j].groupName << endl;
                        isAnswer = true;
                        break;
                    }
                }
                if(isAnswer == true) break;
            }
        }
    }
    return 0;
}