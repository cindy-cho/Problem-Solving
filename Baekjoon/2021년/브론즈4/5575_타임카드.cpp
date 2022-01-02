#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int workingtime[3];
    int h,m,s,hh,mm,ss;
    for(int i=0;i<3;i++){
        cin >> h >> m >> s >> hh >> mm >> ss;
        h = (hh*3600+mm*60+ss) - (h*3600+m*60+s);
        workingtime[i] = h;
    }
    for(int i=0;i<3;i++){
        cout << workingtime[i] / 3600 << " " << (workingtime[i]%3600)/60 << " " << (workingtime[i]%3600)%60<<"\n";
    }
    return 0;
}