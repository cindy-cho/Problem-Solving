#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    int A,B,len=0;
    cin >> N >> M;
    vector < int > student(N);
    for(int i=0;i<M;i++){
        cin >> A >> B;
        if(i==0){
            student[0] = A;
            student[1] = B;
            len = 1;
        }
    }
    return 0;
}