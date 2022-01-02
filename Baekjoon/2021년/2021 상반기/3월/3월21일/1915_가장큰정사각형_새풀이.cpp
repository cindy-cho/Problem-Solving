#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
int main(void){
    int n,m,i,j,ans=0;
    scanf("%d %d",&n,&m);
    vector<string> map(n);
    vector < vector< int> > intMap(n, vector<int> (m,0));
    cin.ignore();
    for(i=0;i<n;i++) {
        getline(cin,map[i]);
        for(j=0;j<m;j++){
            if(map[i][j]=='0') intMap[i][j]=0;
            else{
                intMap[i][j]=1;
                ans=1;
            } 
        }
    }              
    if(ans==0) {
        cout << "0\n";
        return 0;
    }

    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            if(intMap[i][j]==1 && intMap[i-1][j]>0 && intMap[i-1][j-1]>0 && intMap[i][j-1]>0){
                intMap[i][j]= min(intMap[i][j-1],min(intMap[i-1][j], intMap[i-1][j-1]))+1;
                if(intMap[i][j]>ans) ans=intMap[i][j];
            }
        }
    }

    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++) cout << intMap[i][j];
    //     cout <<"\n";
    // }

    cout << ans*ans << "\n";
    
    

    return 0;
}