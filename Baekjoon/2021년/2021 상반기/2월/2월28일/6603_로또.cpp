#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

void combination(vector<int> s, vector<int> comb, int r,int i,int d){
    if(r==0){
        for(int j=0;j<5;j++) cout << comb[j] << " ";
        cout << comb[5] << endl;
    }
    else if(d==s.size()) return;
    else{
        comb[i] = s[d];
        combination(s,comb,r-1,i+1,d+1);
        combination(s,comb,r,i,d+1);
    }
    return;
}
int main(void){
    int k,i,val;
    scanf("%d",&k);
    vector<int> comb(6);

    while(k!=0){
        vector<int> s;
        
        for(i=0;i<k;i++){
            scanf("%d",&val);
            s.push_back(val);
        }
        combination(s,comb,6,0,0);
        printf("\n");
        scanf("%d",&k);
    }
    return 0;
}