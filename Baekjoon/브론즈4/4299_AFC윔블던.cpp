#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int add,sub,A,B;
    cin >> add >> sub;
    A = (add+sub)/2;
    B = (add-sub)/2;
    if( (add+sub)%2!=0){
        cout << "-1\n";
        return 0;
    }
    else if(A<0 || B<0){
        cout << "-1\n";
        return 0;
    }
    cout << A << " " << B << "\n";
    return 0;
}