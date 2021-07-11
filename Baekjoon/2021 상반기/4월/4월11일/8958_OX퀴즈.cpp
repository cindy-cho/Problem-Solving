#include<iostream>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    string result;
    int score,total;
    cin >> T;
    cin.ignore();
    for(int i=0;i<T;i++){
        score = 0;
        total = 0;
        cin >> result;
        for(auto r:result){
            if(r=='O') {
                score++;
                total+=score;
            }
            else{
                score=0;
            }
        }
        cout << total << "\n";
    }
    return 0;
}