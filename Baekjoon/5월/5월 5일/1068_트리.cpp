#include<stdio.h>

int main(void){
    int N,M,ans=0;
    scanf("%d",&N);
    int parent[50];
    int nodes[50];
    int flag = 1;
    for(int i=0;i<N;i++) parent[i]=0;
    for(int i=0;i<N;i++) {
        scanf("%d",&nodes[i]);
        parent[nodes[i]]++;
    }
    scanf("%d",&M);
    parent[nodes[M]]--;
    nodes[M] = -2;
    while(flag==1){
        flag = -1;
        for(int i=0;i<N;i++){
            if(nodes[nodes[i]]==-2) {
                nodes[i] = -2;
                flag = 1;
            }
        }
    }
    
    
    for(int i=0;i<N;i++){
        // cout << nodes[i] << "," << parent[i] << endl;
        if(nodes[i]!=-2 && parent[i]==0) ans ++;
    }
    printf("%d\n",ans);

    return 0;
}