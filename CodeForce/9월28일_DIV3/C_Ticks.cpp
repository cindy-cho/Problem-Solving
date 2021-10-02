#include<iostream>
#include<vector>
#include<queue>
#define endl '\n'
typedef long long ll;

using namespace std;
typedef struct {
    int x;
    int y;
    int yy;
}nextDot;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    int crntK;
    int t;
    int x,y,yy;
    bool isSuit;
    int tx,ty,tty;
    char c;

    cin >> t;
    for(int tc=0;tc<t;tc++){
        isSuit = true;
        cin >> n >> m >> k;
        vector<vector<int>> map(n,vector<int> (m,0));
        queue<nextDot> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                cin >> c;
                if(c=='*') map[i][j]=1;
                else map[i][j] =0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(map[i][j]>=1){
                      
                    isSuit = true;
                    crntK = 1;
                    tx = i-1;
                    ty = j-1;
                    tty = j+1;
                    if(tx>=0 && ty>=0 && tty<m && map[tx][ty]>=1 && map[tx][tty]>=1){
                        map[i][j]++;
                        map[tx][ty]++;
                        map[tx][tty]++;
                        q.push({tx,ty,tty});
                        while(!q.empty()){
                            // cout << x << "," << y << endl;
                            x = q.front().x;
                            y = q.front().y;
                            yy = q.front().yy;
                            
                            q.pop();
                            crntK++;
                            tx = x-1;
                            ty = y-1;
                            tty = yy+1;
                            if(tx>=0 && ty>=0 && tty<m && map[tx][ty]>=1 && map[tx][tty]>=1){
                                map[tx][ty]++;
                                map[tx][tty]++;
                                q.push({tx,ty,tty});
                            }
                        }
                    }
                    if((crntK==1 && map[i][j]==1) || (crntK>1 && crntK<k && map[i][j] > 1)){

                        isSuit = false;
                        // cout << crntK << endl;
                        // cout << i << "," << j <<endl;
                        // cout << map[i][j] << endl;
                    }
                        cout << "( " << i << " , " << j << " ) " << endl;
                        cout << "crntK : " << crntK << endl;
                        for(int pp = 0; pp<n; pp++){
                            for(int qq=0 ; qq <m ; qq++){
                                cout << map[pp][qq] << " " ;
                            }
                            cout << endl;
                        }
                }
                if(isSuit == false) break;
            }
            if(isSuit == false) break;
        }
        if(isSuit==false) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    
    return 0;
}