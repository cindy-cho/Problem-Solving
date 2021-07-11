#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool desc(int a, int b){
    return a>b;
}

int main(void){
    int N;
    vector<int> A, B;
    int i,value,S=0;
    scanf("%d",&N);
    for(i=0;i<N;i++) {
        scanf("%d",&value);
        A.push_back(value);
    }
    for(i=0;i<N;i++) {
        scanf("%d",&value);
        B.push_back(value);
    }
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),desc);
    for(i=0;i<N;i++) S+= A[i]*B[i];
    cout << S << endl;
    return 0;
}