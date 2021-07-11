#include<iostream>
#include<vector>
using namespace std;

int endFlag=-1;
vector < vector <int > > friendship;
void dfs(vector<bool> vst,int s, int depth){
    if(endFlag==1) return ;
    else if(depth == 5){
        endFlag=1;
        return;
    }
    int i,j;
    for(i=0;i<friendship[s].size();i++){
        if(vst[friendship[s][i]]==false){
            vst[friendship[s][i]]=true;
            dfs(vst,friendship[s][i],depth+1);
            vst[friendship[s][i]]=false;
        }
        if(endFlag==1) return;
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M,i,j,a,b;
    cin >> N >> M;
    friendship.resize(N);
    
    vector < bool > vst (N,false);

    for(i=0;i<M;i++){
        cin >> a >> b;
        friendship[a].push_back(b);
        friendship[b].push_back(a);
    }

    for(i=0;i<N;i++){
        vst[i]=true;
        
            
            dfs(vst,i,1);
           
            if(endFlag==1) {
                cout << "1\n";
                return 0;
            }
        
        vst[i]=false;
    }

    cout << "0\n";
 
    return 0;
}