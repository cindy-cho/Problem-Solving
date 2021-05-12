#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int w,h,p,q,t;
    int orgP,orgQ;
    int x,y;
    int pp,qq;
    cin >> w >> h;
    cin >> p >> q ;
    cin >> t;

    p+=t;
    q+=t;
    x = p/w;
    y = q/h;
    p = p%w;
    q = q%h;
    if(p!=0) x++;
    if(q!=0) y++;
    if(x%2==1 && p==0) p = w;
    else if(x%2==0) {
        if(p==0) p=0;
        else p = w-p;
    }
    if(y%2==1 && q==0) q = h;
    else if(y%2==0){
        if(q==0) q=0;
        else q = h-q;
    }
    
    cout << p << " " << q << "\n";
    
    return 0;
}