#include<iostream>
#include<vector>
#include<math.h>
#define endl '\n'
typedef long long ll;

using namespace std;

typedef struct{
    int x;
    int y;
}police;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n ;
    int theif[2], x,y;
    bool check[4] = {false,false,false,false};

    // 상, 하 , 좌, 우
    cin >> n;
    vector<police> p(n);
    // vector<police> p(4);
    // p[0].x = 1000000001;
    // p[0].y = 1000000001;

    // p[1].x = -1000000001;
    // p[1].y = 1000000001;

    // p[2].x = 1000000001;
    // p[2].y = -1000000001;

    // p[3].x = -1000000001;
    // p[3].y = -1000000001;

    for(int i=0;i<n;i++){
        cin >> p[i].x >> p[i].y;
        // if(p[0].x>x && p[0].y>y){
        //     p[0].x = x;
        //     p[0].y= y;
        // }
        // if(p[1].x<x && p[0].y>y){
        //     p[1].x = x;
        //     p[1].y= y;
        // }
        // if(p[2].x>x && p[2].y<y){
        //     p[2].x = x;
        //     p[2].y= y;
        // }
        // if(p[3].x<x && p[3].y<y){
        //     p[3].x = x;
        //     p[3].y= y;
        // }
    }


    cin >> theif[0] >> theif[1];
    for(int i=0;i<n;i++){
        if(p[i].x == theif[0] && p[i].y==theif[1]){
            cout << "NO\n";
            return 0;
        }
        if(p[i].x<=theif[0] && p[i].y<=theif[1]) check[0] = true;
        else if(p[i].x>theif[0] && p[i].y<=theif[1]) check[1] = true;
        else if(p[i].x<=theif[0] && p[i].y>theif[1]) check[2] = true;
        else if(p[i].x>theif[0] && p[i].y>theif[1]) check[3] = true;

    }
    int total=0;
    for(int i=0;i<4;i++) if(check[i]==true) total++;
    if(total>=3 || (check[1]==true && check[2]==true) || (check[0]==true && check[3]==true)) cout << "NO" << endl;
    else cout << "YES\n";

    return 0;
}