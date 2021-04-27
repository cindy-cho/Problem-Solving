#include<iostream>
#include<map>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T,N,A,M;
    cin >> T;
    for(int i=0;i<T;i++){
        map <int,int> notes;
        cin >> N;
        for(int j=0;j<N;j++){
            cin>>A;
            notes.insert({A,1});
        }
        cin >> M;
        for(int j=0;j<M;j++){
            cin >> A;
            if(notes.find(A)==notes.end()) cout << "0\n";
            else cout <<"1\n";
        }
    }
    return 0;
}