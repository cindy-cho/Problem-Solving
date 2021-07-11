#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(pair<int, int>a, pair<int, int>b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(void){
    int N,i,x,y;
    vector <pair < int, int > > sets;

    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d %d",&x,&y);
        sets.push_back(make_pair(x,y));
    }

    sort(sets.begin(),sets.end(),comp);

    for(i=0;i<N;i++) printf("%d %d\n",sets[i].first,sets[i].second);

    return 0;
}