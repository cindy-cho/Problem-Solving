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

    cin >> n;

    vector<police> p(4);
    p[0].x = 1000000001;
    p[0].y = 1000000001;

    p[1].x = -1000000001;
    p[1].y = 1000000001;

    p[2].x = 1000000001;
    p[2].y = -1000000001;

    p[3].x = -1000000001;
    p[3].y = -1000000001;

    for(int i=0;i<n;i++){
        cin >> x >>  y;
        if(p[0].x>x && p[0].y>y){
            p[0].x = x;
            p[0].y= y;
        }
        if(p[1].x<x && p[0].y>y){
            p[1].x = x;
            p[1].y= y;
        }
        if(p[2].x>x && p[2].y<y){
            p[2].x = x;
            p[2].y= y;
        }
        if(p[3].x<x && p[3].y<y){
            p[3].x = x;
            p[3].y= y;
        }
    }


    cin >> theif[0] >> theif[1];

    bool check[4] = {true,true,true,true};

    bool ans = false;

   //up
    bool flg = true;
    for (int i = 0; i < 4; i++) {
        if(abs(p[i].x) == 1000000001 || abs(p[i].y) == 1000000001) continue;
        if (p[i].y >= theif[1]) continue;
        if (abs(p[i].x - theif[0]) > abs(p[i].y - theif[1])) continue;
        flg = false;
    }
    if (flg) ans = true;

   //left
   flg = true;
   for (int i = 0; i < 4; i++) {
       if(abs(p[i].x) == 1000000001 || abs(p[i].y) == 1000000001) continue;
      if (p[i].x >= theif[0])
         continue;
      if (abs(p[i].y - theif[1]) > abs(p[i].x - theif[0]))
         continue;
      flg = false;
   }
   if (flg)
      ans = true;

   //down
   flg = true;
   for (int i = 0; i < 4; i++) {
       if(abs(p[i].x) == 1000000001 || abs(p[i].y) == 1000000001) continue;
      if (p[i].y <= theif[1])
         continue;
      if (abs(p[i].x - theif[0]) > abs(p[i].y - theif[1]))
         continue;
      flg = false;
   }
   if (flg)
      ans = true;

   //right
   flg = true;
   for (int i = 0; i < 4; i++) {
       if(abs(p[i].x) == 1000000001 || abs(p[i].y) == 1000000001) continue;
      if (p[i].x <= theif[0])
         continue;
      if (abs(p[i].y - y) > abs(p[i].x - theif[0]))
         continue;
      flg = false;
   }
   if (flg)
      ans = true;

   if (ans)
      cout << "YES\n";
   else
      cout << "NO\n";

    return 0;
}