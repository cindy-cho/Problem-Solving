#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(void){
    int N,value,i,ansIdx=0,flag=1;
    vector <int> ans,oper;
    stack <int> holder;
\

    scanf("%d",&N);
    
    for(i=0;i<N;i++){
        scanf("%d",&value);
        ans.push_back(value);
    }

    for(i=1;i<=N;i++){
        if(holder.empty() || holder.top()!=ans[ansIdx]){
            holder.push(i);
            oper.push_back(1);
        }
        while(holder.top()==ans[ansIdx]){
            holder.pop();
            oper.push_back(0);
            ansIdx++;
            if(holder.empty()) break;
            if(ansIdx==N) break;
        }
    }
    if(!holder.empty()) printf("NO\n");
    else{
        for(i=0;i<oper.size();i++) {
            if(oper[i]==1) printf("+\n");
            else printf("-\n");
        }
    }
    return 0;
}


