#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(int a, int b){
    return a>b;
}
int main(void){
    int T,N,O;
    int i,j,value;
    int idx,prior;

    scanf("%d",&T);
    
    for(i=0;i<T;i++){
        scanf("%d %d",&N,&O);
        vector <int > v;
        queue <pair <int, int > > q;
        for(j=0;j<N;j++){
            scanf("%d",&value);
            q.push(make_pair(j,value));
            v.push_back(value);
        }
        sort(v.begin(),v.end(),comp);
       
        for(j=0;j<N;j++){
            while(q.front().second != v[j]){
                idx = q.front().first;
                prior = q.front().second;
                q.pop();
                q.push(make_pair(idx,prior));
            }

            if(q.front().first==O) {
                printf("%d\n",j+1);
                break;
            }

            q.pop();
        }
    }
    return 0;
}


