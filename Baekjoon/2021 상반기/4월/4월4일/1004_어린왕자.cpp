#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double T,x1,y1,x2,y2,i,n,j,cx,cy,r;
    // int ans;
    double r1,r2;
    int val,minus;
    vector<int>ans;
    cin >> T;
    for(i=0;i<T;i++){
        cin>> x1 >> y1 >> x2 >> y2 ;
        cin >> n;
        val=0;
        minus=0;
        for(j=0;j<n;j++){
            cin >> cx >> cy >> r;
            r1 = sqrt((cx-x1)*(cx-x1) + (cy-y1)*(cy-y1));
            r2 = sqrt((cx-x2)*(cx-x2) + (cy-y2)*(cy-y2));
            if(r1<r && r2<r) continue;
            if(r1<r) val++;
            else if(r2<r) val++;
        }
        ans.push_back(val);
    }
    for(i=0;i<T;i++) cout << ans[i] << "\n";
    return 0;
}