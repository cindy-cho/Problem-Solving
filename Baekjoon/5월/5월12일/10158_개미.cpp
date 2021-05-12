#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int w,h,p,q,t;
    int x,y;
    int pp,qq;
    cin >> w >> h;
    cin >> p >> q ;
    cin >> t;
    p+=t;
    q+=t;
    cout <<  p%w << "," << q%w << "\n";
    return 0;
}