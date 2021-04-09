#include<iostream>
#include <vector>
#include <queue>
using namespace std;

vector < vector <bool> > map;
vector <bool> visited;

void DFS(int V){
    cout << V+1 << " " ;
    
    visited[V] = true;

    for(int i=0;i<visited.size();i++){
        if(map[V][i]==true && visited[i]==false){
            DFS(i);
        }
    }
    return ;
}

int main(void){
    int N,M,V,i,r,c;
    
    scanf("%d %d %d",&N,&M,&V);

    map.resize (N, vector <bool> (N,false));
    visited.resize (N,false);
    vector < bool > qvisited(N,false);

    for(i=0;i<M;i++){
        scanf("%d %d",&r,&c);
        r--;
        c--;
        map[r][c]= true;
        map[c][r]= true;
    }

    DFS(V-1);

    cout << endl;

    queue <int> q;

    q.push(V-1);

    int front;
    qvisited[V-1] = true;
    while(!q.empty()){
        front = q.front();
        
        cout << front+1 << " " ;


        q.pop();

        for(i=0;i<N;i++){
            if(map[front][i]==true && qvisited[i]==false){
                qvisited[i] = true;
                q.push(i);
            }
        }
    }

    cout << endl;
    

    return 0;
}