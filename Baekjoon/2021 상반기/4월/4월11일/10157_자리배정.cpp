#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int C,R;
    long long int K,i,j;
    long long int stage=0;
    long long int saved=1;
    long long int x=1,y=1;
    cin >> C >> R;
    cin >> K;
    if(C*R < K){
        cout << "0\n";
        return 0;
    }
    /* CCCC
    R
    R
    */
    for(stage=0;;stage+=2){
        if(saved + ((C-stage)+(R-stage)) * 2 - 4 >K) break;
        saved += ((C-stage)+(R-stage)) * 2 - 4 ;
    }
    if(stage!=0){
        x +=stage/2;
        y +=stage/2;
        R -= stage;
        C -= stage;
    }
    if(saved+R-1>=K){
        y += (K-saved);
        cout << x << " " << y << "\n";
        return 0;
    }
    else if(saved+R-1+C-1>=K){
        y+= R-1;
        saved += R-1;
        x+= (K-saved);
        cout << x << " " << y << "\n";
        return 0;
    }
    else if(saved+R-1+C-1+R-1>=K){
        y+=R-1;
        x+=C-1;
        saved += (R+C-2);
        y-= (K-saved);
        cout << x << " " << y << "\n";
        return 0;
    }
    else{
        x+=C-1;
        saved += (R+C+R-3);
        x-=(K-saved);
        cout << x << " " << y << "\n";
        return 0;
    }
    

    return 0;
}