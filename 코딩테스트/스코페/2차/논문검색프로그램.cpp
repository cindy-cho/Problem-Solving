#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> word;

bool cmp(string a, string b){
    return a.length() < b.length();
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,Q,i,j,count,len;
    string sQ;
    cin >> N;
    cin.clear();
    word.resize(N);
    for(i=0;i<N;i++){
        cin >> word[i];
    }
    cin >> Q;
    
    sort(word.begin(),word.end(),cmp);
    cin.clear();
    
    for(i=0;i<Q;i++){
         cin >> sQ;
         count = 0;
         len = sQ.length();
         for(j=0;j<N;j++){
             if(word[j].length()<len) break;
             if(word[j].find(sQ)!=string::npos) count ++;
         }

         cout << count << "\n";
    }
    
    return 0;
}
/*
5
dijkstra
greedy
bfs
backtracking
dynamic
5
dynamic
ynamic
dydynadymic
dydy
dy
*/
/*
5
dijkstra
greedy
bfs
backtracking
dynamic
3
bfs
greedyalgorithm
ra
*/
/*
5
dijkstra
greedy
bfs
backtracking
dynamic
3
bfs
*/