#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int main(void){
    int n,q;
    int i,j,val;
    int type,input;
    int count=0;
    vector <int> a;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++){
        scanf("%d",&val);
        if(val==1) count ++;
        a.push_back(val);
    }
    for(i=0;i<q;i++){
        scanf("%d %d",&type,&input);
        if(type==1){
            if(a[input-1]==1) count --;
            else count ++;
            a[input-1] = 1-a[input-1];
        }
        else if(type==2){
            if(input-1<count) cout << "1" << endl;
            else cout << "0" << endl;
        }
    }


    return 0;
}