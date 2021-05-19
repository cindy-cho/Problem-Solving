#include<iostream>
#include<math.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double diagnoal,height,width,K;
    cin >> diagnoal >> height >> width;
    K = diagnoal*diagnoal / (height*height + width*width);
    K = sqrt(K);
    cout << (int)floor(K*height) << " " << (int)floor(K*width) << "\n";
    return 0;
}