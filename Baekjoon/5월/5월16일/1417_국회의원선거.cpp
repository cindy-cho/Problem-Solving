#include<iostream>
#include<queue>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int tmp;
    int count=0;
    priority_queue <int> votes;
    cin >> N;
    int Dasom,vote;
    cin >> Dasom;
    for(int i=1;i<N;i++){
        cin >> vote;
        votes.push(vote);
    }
    if(N==1){
        cout << "0\n";
        return 0;
    }
    while(Dasom <= votes.top()){
        Dasom++;
        count++;
        tmp = votes.top();
        votes.pop();
        tmp--;
        votes.push(tmp);
    }
    cout << count << "\n";
    return 0;
}