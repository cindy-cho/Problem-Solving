#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void){
    int N,K,i,sister,time=0,now=0;
    
    scanf("%d %d",&N,&K);
    vector <bool> visited (100000,false);
    queue <pair < int, int > > q;
    q.push(make_pair(K,0));
    visited[K]= true;
    while(!q.empty()){
        sister = q.front().first;
        now = q.front().second;
        if(sister==N)  break;
        q.pop();
        if(sister%2==0 && sister!=0 && visited[sister/2]==false){
            q.push(make_pair(sister/2,now+1));
            visited[sister/2]=true;
        } 
        if(sister+1<=100000 && visited[sister+1]==false) {
            q.push(make_pair(sister+1,now+1));
            visited[sister+1]=true;
        }
        if(sister-1>=0 && visited[sister-1]==false) {
            q.push(make_pair(sister-1,now+1));
            visited[sister-1]=true;
        }
    }

    cout << now << endl;
    return 0;
}
