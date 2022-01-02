#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int check[6]={1,1,2,2,2,8};
    int in;
    for(int i=0;i<6;i++){
        cin>> in;
        cout << check[i]-in << " ";
    }
    return 0;
}