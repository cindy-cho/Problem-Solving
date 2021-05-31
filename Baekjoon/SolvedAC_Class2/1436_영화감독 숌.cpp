#include<iostream>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int start = 665;
    size_t nPos;
    string conversion,check="666";
    cin >> N;
    while(N>0){
        start++;
        conversion = to_string(start);
        nPos = conversion.find(check);
        if(nPos!= string::npos){
            N--;
        }
    }
    cout << start << endl;
    return 0;
}