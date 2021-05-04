#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double min=1000000,max=-1000000;
    double N,in;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> in;
        if(in<min) min = in;
        if(in>max) max = in;
    }
    cout << min << " " << max << "\n";
    return 0;
}