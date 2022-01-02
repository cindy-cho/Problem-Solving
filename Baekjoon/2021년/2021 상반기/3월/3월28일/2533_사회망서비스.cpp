#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

vector<vector <int> > community;

int N;
int ansSample;
int flag;
bool cmp (vector<int> a , vector <int> b){
    return a[1] > b[1];
}

void earlyAdapter(int A,int leader,int affected,vector<bool> vst){ 
    // cout << "A: " << A << ", leader : " << leader << ",  affected : " << affected << endl;
    if(flag==1) return;
    if(affected==N) {
        flag=1;
        ansSample = leader;
        return;
    }
    int i;
    vst[A]=true;
   for(i=2;i<community[A].size();i++){
       if(vst[community[A][i]]==false){
            vst[community[A][i]]=true;
            affected++;
        }
   }
   if(affected==N) return;
   
   for(i=0;i<N;i++){
       if(vst[i]==false) { 
           earlyAdapter(i,leader+1,affected+1,vst);
        }
        if(affected==N) return;
   }

   for(i=2;i<community[A].size();i++){
       vst[community[A][i]]=false;
       earlyAdapter(i,leader+1,affected+1,vst);
       vst[community[A][i]]=true;
   }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,u,v;
    int ans=1000000;
    int max=0;
    cin >> N;
    community.resize(N, vector<int> (2,0));
    vector<bool> vst(N,false);

    for(i=0;i<N-1;i++){
        community[i][0]=i;
        cin >> u >> v;
        community[u-1][1]++;
        community[v-1][1]++;
        if(community[u-1][1]>max) max =community[u-1][1];
        if(community[v-1][1]>max) max =community[v-1][1];
        community[u-1].push_back(v-1);
        community[v-1].push_back(u-1);
    }
    
    // sort(community.begin(),community.end(),cmp);
 
    for(i=0;i<N;i++){
        if(community[i][0]==max){
        flag = -1;
        earlyAdapter(community[i][0],1,1,vst);
        if(ansSample<ans) ans = ansSample;}

    }

    cout << ans <<"\n";
    
    return 0;
}